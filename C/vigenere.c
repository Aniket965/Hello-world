/**********************************************
 * Author: Tran Tat Huy - ICT58               *
 * Hanoi University of Science and Technology *
 **********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define epsilon 0.006
#define EnglishIC 0.067
char *key = "luck";
char dict[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};

char* encode(char *msg){
  char* cipher = (char*)malloc(sizeof(char)*strlen(msg));
  int i;
  for (i = 0; i < strlen(msg); ++i) {
    if (msg[i] < 'a' || msg[i] > 'z'){
      cipher[i] = msg[i];
    }
    else{
      cipher[i] = dict[(msg[i] - 'a' + key[i%strlen(key)] - 'a')% 26];
    }
  }
  return cipher;
}

double calculateIC(char *msg){
  int N = 0;
  int c = 26;
  int f[26];
  int sum = 0;
  //initialize
  for (int i = 0; i < 26; ++i) {
    f[i] = 0;
  }
  //count frequency and number of char
  for (int i = 0; i < strlen(msg); ++i) {
    if (msg[i] >= 'a' && msg[i] <= 'z'){
      f[msg[i]-'a']++;
      N++;
    }
  }
  //sum of English alphabet
  for (int i = 0; i < 26; ++i) {
    sum = sum + f[i] * (f[i]-1);

  }
  return (double)sum/(N*(N-1));
}

//Dynamic Array style
int findLength_DA(char *ciphertext){
  int keyLength = 1,i;
  while(keyLength < 10){
    printf("\nkeylength = %d\n",keyLength);
    char **c = malloc( keyLength * sizeof( char* ));
    if (( c = malloc( keyLength * sizeof( char* ))) == NULL ) { return 0; }

    //initialize multi-D array
    int numberOfRow = keyLength;
    for (i = 0; i < keyLength; i++) {
      c[i] = malloc( (strlen(ciphertext) / numberOfRow) * sizeof(char) );
      if ((c[i] = malloc(sizeof(char) * (strlen(ciphertext) / numberOfRow))) == NULL) {
        printf("fail to malloc array\n");
      }
    }
    //distribute cipher text into subgroups
    int start = 0;
    while (numberOfRow > 0) {
      int index = 0;
      for (i = start+numberOfRow-1; i < strlen(ciphertext); i=i+keyLength) {
        if(ciphertext[i] >= 'a' && ciphertext[i] <= 'z'){
          c[numberOfRow][index] = ciphertext[i];
          index++;
        }
      }
      numberOfRow--;
    }

    double averageIC;
    double sum = 0;
    for (int j = 0; j < keyLength; ++j) {
      sum = sum + calculateIC(c[j]);
    }
    printf("Sum of ICs = %f\n",sum);
    averageIC = sum/keyLength;
    printf("average IC = %f\n",averageIC);
    if(abs(averageIC - EnglishIC) <= epsilon) return keyLength;
    keyLength++;
  }
  return 0;
}

//String Array style
char* stradd(const char* a, const char* b){
  size_t len = strlen(a) + 1;
  char *ret = (char*)malloc(len * sizeof(char) + 1);
  *ret = '\0';
  return strcat(strcat(ret, a) ,b);
}

double abs_double(double a, double b){
  if((a-b)<0) return (b-a);
  return (a-b);
}

int findLength_SA(char *ciphertext){
  int keyLength = 1,i;
  while(keyLength < 10){
    printf("\n======================================\n");
    printf("ATTEMP KEY LENGTH = %d\n",keyLength);
    char *c = (char*)malloc(sizeof(char));

    //distribute cipher text into subgroups
    int numberOfRow = keyLength;
    int start = 0, count = 0;
    while (numberOfRow > 0) {
      //sub-cipher-text extraction
      for (i = start+numberOfRow-1; i < strlen(ciphertext); i=i+keyLength) {
        if(ciphertext[i] >= 'a' && ciphertext[i] <= 'z'){
          //printf("|%d %c",i,ciphertext[i]);
          size_t len = strlen(c);
          c = realloc(c,len + 1 + 1 ); /* one for extra char, one for trailing zero */
          c[len] = ciphertext[i];
          c[len + 1] = '\0';
        }
      }
      //calculate IC
      double subcipherIC = calculateIC(c);
      printf("\nBlah: %s\n",c);
      printf("IC of subgroup %d = %f\n",numberOfRow,subcipherIC);
      if(abs_double(subcipherIC,EnglishIC) <= epsilon ) count++;
      printf("The different: %f\n",abs_double(subcipherIC,EnglishIC));
      if(count == keyLength)
        return keyLength;
      numberOfRow--;
    }

    keyLength++;
  }
  return 0;
}


int main(){
  char *msg = "the first thing to note is that there is no guarantee that the period of key\n that we find is the actual key used. If the message is very long we can be\n almost certain of being correct, but the methods provided here are approximate.";
  /*
  char *msg = "A minute examination of the circumstances\nserved only to make the case more complex. In\nthe first place, no reason could be given why the\nyoung man should have fastened the door upon\n"
          +"the inside. There was the possibility that the murderer\nhad done this and had afterwards escaped\n"
          +"by the window. The drop was at least twenty feet,\nhowever, and a bed of crocuses in full bloom lay\n"
          +"beneath. Neither the flowers nor the earth showed\nany sign of having been disturbed, nor were there\n"
          +"any marks upon the narrow strip of grass which\nseparated the house from the road. Apparently,\n"
          +"therefore, it was the young man himself who had\nfastened the door. But how did he come by his\n"
          +"death? No one could have climbed up to the window\nwithout leaving traces. Suppose a man had\n"
          +"fired through the window, it would indeed be a remarkable\n"
          +"shot who could with a revolver inflict so\n"
          +"deadly a wound. Again, Park Lane is a frequented\n"
          +"thoroughfare, and there is a cab-stand within a\n"
          +"hundred yards of the house. No one had heard a\n"
          +"shot. And yet there was the dead man, and there\n"
          +"the revolver bullet, which had mushroomed out, as\n"
          +"soft-nosed bullets will, and so inflicted a wound\n"
          +"which must have caused instantaneous death. Such\n"
          +"were the circumstances of the Park Lane Mystery,\n"
          +"which were further complicated by entire absence\n"
          +"of motive, since, as I have said, young Adair was\n"
          +"not known to have any enemy, and no attempt had\n"
          +"been made to remove the money or valuables in\n"
          +"the room";

  for(int i = 0; msg[i]; i++){
    msg[i] = tolower(msg[i]);
  }
   */
  printf(">>The original text:\n\n%s\n",msg);
  printf("\nThe IC: %f\n",calculateIC(msg));
  printf("================================================================================\n");
  printf(">>The cipher text:\n\n%s\n",encode(msg));
  //DA - Dynamic Array || SA - String Array
  printf("The length of key is: %d\n",findLength_SA(encode(msg)));
  return 0;
}