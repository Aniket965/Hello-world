#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#define MAX_NUMBER 100
#define MAX_NAME_SIZE 21
#define MAX_INPUT_SIZE 15

/*******************************
Declarations & Global Variables
*******************************/
void randomNumber();
void getName();
void userGuess();

char name[MAX_NAME_SIZE];
int randomNum;

typedef enum boolean{
  false,
  true
} BOOL;

/******************************
Functions
*******************************/
int main(int argc, char const *argv[]) {

    randomNumber();

    //Only continue if the random number is valid
    if(randomNum >=0 && randomNum < MAX_NUMBER){

      getName();
      userGuess();

    } else {
      printf("Sorry but there seems to be an error. We will work to fix it as soon as possible.");
    }
}

void randomNumber(){

  //Generate the random number
  srand(time(NULL));
  randomNum = rand() % MAX_NUMBER;

  assert(randomNum >= 0 && randomNum < MAX_NUMBER);
}

void getName(){
  printf("Hello! Welcome to Guess My Number. What is your name?\n");

  while(fgets(name, MAX_NAME_SIZE, stdin) == NULL){
    printf("Please enter a name under 20 characters.\n");
  }

  assert(name != NULL);

  //Trim the newline character of the name string
  name[strcspn(name,"\n")] = 0;

  assert(name != NULL);

  printf("Hi %s, let's get started!\n", name);
}

void userGuess(){
  char input[MAX_INPUT_SIZE];
  int number;
  int numTries = 0;
  BOOL checkInput = false;

  assert(numTries == 0);

  printf("I am thinking of a number between 0 & 99. What do you think the number is?\n");

  while(checkInput == false && fgets(input, MAX_INPUT_SIZE, stdin) != NULL){
    number = atoi(input);
    if(number <= 0 || number >= 100)
      printf("Please enter a valid number between 0 & 99.\n");
    else {
      numTries++;
      if(number < randomNum)
        printf("That number is too low. Please try again.\n");
      else if(number > randomNum)
        printf("That number is too high. Please try again.\n");
      else if(number == randomNum){
        printf("Good Job! You guessed my number in %d tries.\n", numTries);
        checkInput = true;
      }
    }
  }

}
