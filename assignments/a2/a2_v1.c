/*
 * Filename: a2_v1.c
 * Purpose: Reads character inputs and prints them
 * Authors: Noah Halpern & Aleck Zhao
 * Date Created: 9.14.2016
 * Date Modified: 9.14.2016
 */

#include <stdio.h>

/* Main for reading input. */
int main(){
    
    char in = getchar();

    // while input is not the end-of-file character
    while(in != EOF){
    
        printf("%c", in);

	// gets new input
        in = getchar();

    }

    // default
    return 0;

}
