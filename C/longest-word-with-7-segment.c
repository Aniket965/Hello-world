/*

This program searches through 370,000+ words and finds the longest word that can be displayed with 7-segment displays.

Author: Muhammad Arifur Rahman (https://github.com/theintel)

Created: 17 October, 2018

Wordlist credits:

https://github.com/dwyl/english-words

words.txt link: https://github.com/dwyl/english-words/blob/master/words_alpha.txt

Inspired by Tom Scott: https://youtu.be/zp4BMR88260

*/

#include"stdio.h"

#include"string.h"

#include"math.h"

#include"stdlib.h"

#include"ctype.h"

#include"limits.h"

#include"time.h"

#include"stdbool.h"

#define ll long long

int main()

{

	freopen("words.txt", "r", stdin); //read the words from the text file	clock_t lnh=clock(); //to record the execution time

	ll t,d=1,max=0;

	char maxword[250];

	char banned[]="GKMQVWXZ"; //letters not writable in 7-segment display

	

	char word[250];

	while(scanf("%s",word)!=EOF)

	{

	ll n,i;

	bool alpha[26]={0}; //to record which letters are present in a word

	

	ll l =strlen(word);

	

	for(i=0;i<l;i++)

		alpha[tolower(word[i])-'a']=1;

	

	for(i=0;i<strlen(banned);i++)

	if(alpha[tolower(banned[i])-'a']==1) //if a banned letter is present, ignore the word

	break;

	

	if(i==strlen(banned))

	{

		strcpy(maxword,(l>max)?word:maxword);

		max=(l>max)?l:max;

	}

	

	}

	

	printf("Longest Word: %s",maxword);

	printf("\n");

	

	clock_t cls=clock();

	printf("Execution Time: %fms\n",(double)((cls-lnh)*1000)/CLOCKS_PER_SEC);

	return 0;

}
