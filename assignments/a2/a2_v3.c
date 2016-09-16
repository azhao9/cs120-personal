/*
 * Filename: a2_v3.c
 * Purpose: Reads characters and prints number of characters, words, and lines
 * Authors: Noah Halpern & Aleck Zhao
 * Date Created: 9.14.2016
 * Date Modified: 9.14.2016
 */

#include <stdio.h>
#include <ctype.h>

/* Main for reading input and counting characters, words, and lines */
int main(){
    
    char in = getchar();
    
    // counters
    int chars = 0;
    int space = 0;
    int lines = 0;

    // boolean keeping track of if we're currently in a word
    int inWord = 0;

    // while input is not end-of-file character
    while(in != EOF){
    	    
        if(isspace(in)){

            if(inWord==1){
	
	    	// increments number of spaces (equal to number of words)    
                space ++;

		// no longer in a word
                inWord = 0;

            }
        }
        
	// if input is punctuation and not in word
        else if(ispunct(in) && inWord == 0){
	
	    // still not in a word	
            inWord = 0;

        }

	// if not space, not punctuation
        else{
	    
	    // still in word
            inWord = 1;

        }

	// if newline character detected
        if(in == '\n'){
	
	    // increment number of lines	
            lines ++;

        }
	
	// increment number of characters
        chars ++;
        
	// gets new input
        in = getchar();

    }

    // output
    printf("-------------\n");
    printf("%d lines\n", lines);
    printf("%d words\n", space);
    printf("%d characters\n", chars);

    // default
    return 0;

}
