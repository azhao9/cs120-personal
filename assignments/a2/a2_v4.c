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
    int chars = 0;
    int wchars = 0;
    int space = 0;
    int inWord = 0;
    int lines = 0;

    while(in != EOF){
        
        if(isspace(in)){

            if(inWord==1){

                space ++;
                inWord = 0;

            }
        }
        
        else if(ispunct(in) && inWord == 0){

            inWord = 0;

        }

        else{

            inWord = 1;

        }

        if(in == '\n'){

            lines ++;

        }

        if(!isspace(in) && !ispunct(in)){

            wchars ++;

        }

        chars ++;
        
        in = getchar();

    }

    float avg;

    if(space != 0){

        avg = (float)wchars/(float)space;

    }

    else{

        avg = 0;

    }

    printf("-------------\n");
    printf("%d lines\n", lines);
    printf("%d words\n", space);
    printf("%d characters\n", chars);
    printf("Avg word length: %.1f characters\n", avg);

    return 0;

}
