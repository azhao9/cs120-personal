/*
 * Filename: a2_v4.c
 * Purpose: Reads characters and prints number of characters, words, lines, and average length of words
 * Authors: Noah Halpern & Aleck Zhao
 * Date Created: 9.14.2016
 * Date Modified: 9.14.2016
 */

#include <stdio.h>
#include <ctype.h>

int main(){
    	
    char in = getchar();
    
    // counters
    int chars = 0;
    int wchars = 0;
    int space = 0;
    int lines = 0;

    // boolean if we're currently in a word
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
        
	// if input is punctuation and not in a word
        else if(ispunct(in) && inWord == 0){

	    // still not in a word	
            inWord = 0;

        }

	// if not space, not puncutation
        else{
	
	    // still in a word
            inWord = 1;

        }

	// if newline character detected
        if(in == '\n'){
	
	    // increment number of lines
            lines ++;

        }

	// if not space and not punctuation
        if(!isspace(in) && !ispunct(in)){

	    // increment number of word-characters	
            wchars ++;


        }

	// increment number of characters
        chars ++;
        
	// get new input
        in = getchar();

    }

    // average number of characters per word
    float avg;


    if(space != 0){
	// number of word-chars divided by number of words
        avg = (float)wchars/(float)space;

    }
    // case when no words
    else{
	
	// average length is 0
        avg = 0;

    }

    // output
    printf("-------------\n");
    printf("%d lines\n", lines);
    printf("%d words\n", space);
    printf("%d characters\n", chars);
    // round to 1 decimal point
    printf("Avg word length: %.1f characters\n", avg);

    // default
    return 0;

}
