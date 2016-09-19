#include <stdio.h>
#include <string.h>

/* 
   In class exercise Ex-3-.
   Practice using string functions and writing helper methods.
*/



/*
  Returns in the third argument the concatenation of the first
  argument and the second argument, provided that there is
  sufficient space in third argument, as specified by the fourth.
  e.g.
      concat("alpha", "beta", result, 10) puts "alphabeta" into result and returns 0
      concat("alpha", "gamma", result, 10) puts nothing into result and returns 1

 */
int concat(char word1[], char word2[], char result[], int result_cap){

  int len1 = strlen(word1);
  int len2 = strlen(word2);
  
  if (len1 + len2 >= result_cap) {
	  return 1;
  } else {
	  for (int i = 0; i < len1; i++) {
		  result[i] = word1[i];
	  }

	  for (int i = 0; i < len2 + 1; i++) {
		  result[i + len1] = word2[i];
	  }

	  return 0;
  }

}

int interleave(char word1[], char word2[], char word3[], char result[], int result_cap) {

  int len1 = strlen(word1); 
  int len2 = strlen(word2);
  int len3 = strlen(word3);

  if (len1 + len2 + len3 >= result_cap) {
	  return 1;
  } else {

  }

	  

}

int main() {

  char word1[11];  //allow up to 10 chars, then room for '/0' terminator
  char word2[11];  //allow up to 10 chars, then room for '/0' terminator

  scanf("%s", word1);
  scanf("%s", word2);

  int result_cap;
  scanf("%d", &result_cap);
  char result[result_cap];

  if(!concat(word1, word2, result, result_cap)) {
    printf("Concatenation was successful: %s\n", result);
  } else {
    printf("Concatenation was not successful.\n");
  }

  return 0;
}

