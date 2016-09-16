/*
 * Filename: a2_v2.c
 * Purpose: Reads characters and prints number of characters read 
 * Authors: Noah Halpern & Aleck Zhao
 * Date Created: 9.14.2016
 * Date Modified: 9.14.2016
 */

#include <stdio.h>

/* Main to read input and count characters */
int main(){
    
    char in = getchar();

    // counter for number of characters
    int count = 0;

    // while input is not end-of-file character
    while(in != EOF){
        
	// increments count	    
        count ++;

	// gets new input
        in = getchar();

    }

    // output
    printf("-------------\n");
    printf("%d characters\n", count);

    // default
    return 0;

}
