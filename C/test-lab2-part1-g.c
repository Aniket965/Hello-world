/*
 * test-lab2-part1-g /classfs/dir1 /classfs/dir2
 *
 * Test correctness by creating
 * and deleting files in the same underlying directory
 * via two different yfs client.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

char d1[512], d2[512];
extern int errno;

char big[20001];
char huge[65536];

void
create1(const char *d, const char *f, const char *in)
{
  int fd;
  char n[512];

  /*
   * The FreeBSD NFS client only invalidates its caches
   * cache if the mtime changes by a whole second.
   */
  sleep(1);

  sprintf(n, "%s/%s", d, f);
  fd = creat(n, 0666);
  if(fd < 0){
    fprintf(stderr, "test-lab2-part1-g: create(%s): %s\n",
            n, strerror(errno));
    exit(1);
  }
  if(write(fd, in, strlen(in)) != strlen(in)){
    fprintf(stderr, "test-lab2-part1-g: write(%s): %s\n",
            n, strerror(errno));
    exit(1);
  }
  if(close(fd) != 0){
    fprintf(stderr, "test-lab2-part1-g: close(%s): %s\n",
            n, strerror(errno));
    exit(1);
  }
}

void
check1(const char *d, const char *f, const char *in)
{
  int fd, cc;
  char n[512], buf[21000];

  sprintf(n, "%s/%s", d, f);
  fd = open(n, 0);
  if(fd < 0){
    fprintf(stderr, "test-lab2-part1-g: open(%s): %s\n",
            n, strerror(errno));
    exit(1);
  }
  errno = 0;
  cc = read(fd, buf, sizeof(buf) - 1);
  if(cc != strlen(in)){
    fprintf(stderr, "test-lab2-part1-g: read(%s) returned too little %d%s%s\n",
            n,
            cc,
            errno ? ": " : "",
            errno ? strerror(errno) : "");
    exit(1);
  }
  close(fd);
  buf[cc] = '\0';
  if(strncmp(buf, in, strlen(n)) != 0){
    fprintf(stderr, "test-lab2-part1-g: read(%s) got \"%s\", not \"%s\"\n",
            n, buf, in);
    exit(1);
  }
}

void
unlink1(const char *d, const char *f)
{
  char n[512];

  sleep(1);

  sprintf(n, "%s/%s", d, f);
  if(unlink(n) != 0){
    fprintf(stderr, "test-lab2-part1-g: unlink(%s): %s\n",
            n, strerror(errno));
    exit(1);
  }
}

void
checknot(const char *d, const char *f)
{
  int fd;
  char n[512];

  sprintf(n, "%s/%s", d, f);
  fd = open(n, 0);
  if(fd >= 0){
    fprintf(stderr, "test-lab2-part1-g: open(%s) succeeded for deleted file\n", n);
    exit(1);
  }
}

void
append1(const char *d, const char *f, const char *in)
{
  int fd;
  char n[512];

  sleep(1);

  sprintf(n, "%s/%s", d, f);
  fd = open(n, O_WRONLY|O_APPEND);
  if(fd < 0){
    fprintf(stderr, "test-lab2-part1-g: append open(%s): %s\n",
            n, strerror(errno));
    exit(1);
  }
  if(write(fd, in, strlen(in)) != strlen(in)){
    fprintf(stderr, "test-lab2-part1-g: append write(%s): %s\n",
            n, strerror(errno));
    exit(1);
  }
  if(close(fd) != 0){
    fprintf(stderr, "test-lab2-part1-g: append close(%s): %s\n",
            n, strerror(errno));
    exit(1);
  }
}

// write n characters starting at offset start,
// one at a time.
void
write1(const char *d, const char *f, int start, int n, char c)
{
  int fd;
  char name[512];

  sleep(1);

  sprintf(name, "%s/%s", d, f);
  fd = open(name, O_WRONLY|O_CREAT, 0666);
  if (fd < 0 && errno == EEXIST)
    fd = open(name, O_WRONLY, 0666);
  if(fd < 0){
    fprintf(stderr, "test-lab2-part1-g: open(%s): %s\n",
            name, strerror(errno));
    exit(1);
  }
  if(lseek(fd, start, 0) != (off_t) start){
    fprintf(stderr, "test-lab2-part1-g: lseek(%s, %d): %s\n",
            name, start, strerror(errno));
    exit(1);
  }
  for(int i = 0; i < n; i++){
    if(write(fd, &c, 1) != 1){
      fprintf(stderr, "test-lab2-part1-g: write(%s): %s\n",
              name, strerror(errno));
      exit(1);
    }
    if(fsync(fd) != 0){
      fprintf(stderr, "test-lab2-part1-g: fsync(%s): %s\n",
              name, strerror(errno));
      exit(1);
    }
  }
  if(close(fd) != 0){
    fprintf(stderr, "test-lab2-part1-g: close(%s): %s\n",
            name, strerror(errno));
    exit(1);
  }
}

// check that the n bytes at offset start are all c.
void
checkread(const char *d, const char *f, int start, int n, char c)
{
  int fd;
  char name[512];

  sleep(1);

  sprintf(name, "%s/%s", d, f);
  fd = open(name, 0);
  if(fd < 0){
    fprintf(stderr, "test-lab2-part1-g: open(%s): %s\n",
            name, strerror(errno));
    exit(1);
  }
  if(lseek(fd, start, 0) != (off_t) start){
    fprintf(stderr, "test-lab2-part1-g: lseek(%s, %d): %s\n",
            name, start, strerror(errno));
    exit(1);
  }
  for(int i = 0; i < n; i++){
    char xc;
    if(read(fd, &xc, 1) != 1){
      fprintf(stderr, "test-lab2-part1-g: read(%s): %s\n",
              name, strerror(errno));
      exit(1);
    }
    if(xc != c){
      fprintf(stderr, "test-lab2-part1-g: checkread off %d %02x != %02x\n",
              start + i, xc, c);
      exit(1);
    }
  }
  close(fd);
}


void
createn(const char *d, const char *prefix, int nf, bool possible_dup)
{
  int fd, i;
  char n[512];

  /*
   * The FreeBSD NFS client only invalidates its caches
   * cache if the mtime changes by a whole second.
   */
  sleep(1);

  for(i = 0; i < nf; i++){
    sprintf(n, "%s/%s-%d", d, prefix, i);
    fd = creat(n, 0666);
    if (fd < 0 && possible_dup && errno == EEXIST)
      continue;
    if(fd < 0){
      fprintf(stderr, "test-lab2-part1-g: create(%s): %s\n",
              n, strerror(errno));
      exit(1);
    }
    if(write(fd, &i, sizeof(i)) != sizeof(i)){
      fprintf(stderr, "test-lab2-part1-g: write(%s): %s\n",
              n, strerror(errno));
      exit(1);
    }
    if(close(fd) != 0){
      fprintf(stderr, "test-lab2-part1-g: close(%s): %s\n",
              n, strerror(errno));
      exit(1);
    }
  }
}

void
checkn(const char *d, const char *prefix, int nf)
{
  int fd, i, cc, j;
  char n[512];

  for(i = 0; i < nf; i++){
    sprintf(n, "%s/%s-%d", d, prefix, i);
    fd = open(n, 0);
    if(fd < 0){
      fprintf(stderr, "test-lab2-part1-g: open(%s): %s\n",
              n, strerror(errno));
      exit(1);
    }
    j = -1;
    cc = read(fd, &j, sizeof(j));
    if(cc != sizeof(j)){
      fprintf(stderr, "test-lab2-part1-g: read(%s) returned too little %d%s%s\n",
              n,
              cc,
              errno ? ": " : "",
              errno ? strerror(errno) : "");
      exit(1);
    }
    if(j != i){
      fprintf(stderr, "test-lab2-part1-g: checkn %s contained %d not %d\n",
              n, j, i);
      exit(1);
    }
    close(fd);
  }
}

void
unlinkn(const char *d, const char *prefix, int nf)
{
  char n[512];
  int i;

  sleep(1);

  for(i = 0; i < nf; i++){
    sprintf(n, "%s/%s-%d", d, prefix, i);
    if(unlink(n) != 0){
      fprintf(stderr, "test-lab2-part1-g: unlink(%s): %s\n",
              n, strerror(errno));
      exit(1);
    }
  }
}

int
compar(const void *xa, const void *xb)
{
  char *a = *(char**)xa;
  char *b = *(char**)xb;
  return strcmp(a, b);
}

void
dircheck(const char *d, int nf)
{
  DIR *dp;
  struct dirent *e;
  char *names[1000];
  int nnames = 0, i;

  dp = opendir(d);
  if(dp == 0){
    fprintf(stderr, "test-lab2-part1-g: opendir(%s): %s\n", d, strerror(errno));
    exit(1);
  }
  while((e = readdir(dp))){
    if(e->d_name[0] != '.'){
      if(nnames >= sizeof(names)/sizeof(names[0])){
        fprintf(stderr, "warning: too many files in %s\n", d);
      }
      names[nnames] = (char *) malloc(strlen(e->d_name) + 1);
      strcpy(names[nnames], e->d_name);
      nnames++;
    }
  }
  closedir(dp);

  if(nf != nnames){
    fprintf(stderr, "test-lab2-part1-g: wanted %d dir entries, got %d\n", nf, nnames);
    exit(1);
  }

  /* check for duplicate entries */
  qsort(names, nnames, sizeof(names[0]), compar);
  for(i = 0; i < nnames-1; i++){
    if(strcmp(names[i], names[i+1]) == 0){
      fprintf(stderr, "test-lab2-part1-g: duplicate directory entry for %s\n", names[i]);
      exit(1);
    }
  }

  for(i = 0; i < nnames; i++)
    free(names[i]);
}

void
reap (int pid)
{
  int wpid, status;
  wpid = waitpid (pid, &status, 0);
  if (wpid < 0) {
    perror("waitpid");
    exit(1);
  }
  if (wpid != pid) {
    fprintf(stderr, "unexpected pid reaped: %d\n", wpid);
    exit(1);
  }
  if(!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
    fprintf(stderr, "child exited unhappily\n");
    exit(1);
  }
}

int
main(int argc, char *argv[])
{
  int pid, i;

  if(argc != 3){
    fprintf(stderr, "Usage: test-lab2-part1-g dir1 dir2\n");
    exit(1);
  }

  sprintf(d1, "%s/d%d", argv[1], getpid());
  if(mkdir(d1, 0777) != 0){
    fprintf(stderr, "test-lab2-part1-g: failed: mkdir(%s): %s\n",
            d1, strerror(errno));
    exit(1);
  }
  sprintf(d2, "%s/d%d", argv[2], getpid());
  if(access(d2, 0) != 0){
    fprintf(stderr, "test-lab2-part1-g: failed: access(%s) after mkdir %s: %s\n",
            d2, d1, strerror(errno));
    exit(1);
  }

  setbuf(stdout, 0);

  for(i = 0; i < sizeof(big)-1; i++)
    big[i] = 'x';
  for(i = 0; i < sizeof(huge)-1; i++)
    huge[i] = '0';

  printf("Create then read: ");
  create1(d1, "f1", "aaa");
  check1(d2, "f1", "aaa");
  check1(d1, "f1", "aaa");
  printf("OK\n");

  printf("Unlink: ");
  unlink1(d2, "f1");
  create1(d1, "fx1", "fxx"); /* checknot f1 fails w/o these */
  unlink1(d1, "fx1");
  checknot(d1, "f1");
  checknot(d2, "f1");
  create1(d1, "f2", "222");
  unlink1(d2, "f2");
  checknot(d1, "f2");
  checknot(d2, "f2");
  create1(d1, "f3", "333");
  check1(d2, "f3", "333");
  check1(d1, "f3", "333");
  unlink1(d1, "f3");
  create1(d2, "fx2", "22"); /* checknot f3 fails w/o these */
  unlink1(d2, "fx2");
  checknot(d2, "f3");
  checknot(d1, "f3");
  printf("OK\n");

  printf("Append: ");
  create1(d2, "f1", "aaa");
  append1(d1, "f1", "bbb");
  append1(d2, "f1", "ccc");
  check1(d1, "f1", "aaabbbccc");
  check1(d2, "f1", "aaabbbccc");
  printf("OK\n");

  printf("Readdir: ");
  dircheck(d1, 1);
  dircheck(d2, 1);
  unlink1(d1, "f1");
  dircheck(d1, 0);
  dircheck(d2, 0);
  create1(d2, "f2", "aaa");
  create1(d1, "f3", "aaa");
  dircheck(d1, 2);
  dircheck(d2, 2);
  unlink1(d2, "f2");
  dircheck(d2, 1);
  dircheck(d1, 1);
  unlink1(d2, "f3");
  dircheck(d1, 0);
  dircheck(d2, 0);
  printf("OK\n");

  printf("Many sequential creates: ");
  createn(d1, "aa", 10, false);
  createn(d2, "bb", 10, false);
  dircheck(d2, 20);
  checkn(d2, "bb", 10);
  checkn(d2, "aa", 10);
  checkn(d1, "aa", 10);
  checkn(d1, "bb", 10);
  unlinkn(d1, "aa", 10);
  unlinkn(d2, "bb", 10);
  printf("OK\n");

  printf("Write 20000 bytes: ");
  create1(d1, "bf", big);
  check1(d1, "bf", big);
  check1(d2, "bf", big);
  unlink1(d1, "bf");
  printf("OK\n");

  printf("test-lab2-part1-g: Passed all tests.\n");

  exit(0);
  return(0);
}
