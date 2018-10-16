#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv){
  FILE *fp;

  fp = fopen("./words_alpha.txt", "r");
  char *word = argv[1];
  char buffer[1024];
  clock_t timer;
  timer = clock();
  while(fscanf(fp, "%1023s", buffer) ==1){
    if(strcmp(buffer, word) == 0){
      //printf("%s", word);
      //printf(" was found.\n");
      break;
    }
  }
  timer = clock()-timer;
  fclose(fp);
  double time_taken = ((double)timer)/CLOCKS_PER_SEC;
  //printf("%f\n", time_taken);
  FILE *fp2 = fopen("./logs/clog.txt", "a");
  fprintf(fp2, "%f\n", time_taken);
  fclose(fp2);
}
