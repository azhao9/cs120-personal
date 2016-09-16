/*
 * Filename: a2_v2.c
 * Purpose: Reads characters and prints number of characters read 
 * Authors: Noah Halpern & Aleck Zhao
 * Date Created: 9.14.2016
 * Date Modified: 9.14.2016
 */

#include <stdio.h>

int main(){
    
    char in = getchar();
    int count = 0;

    while(in != EOF){
        
        count ++;
        in = getchar();

    }

    printf("-------------\n");
    printf("%d characters\n", count);

    return 0;

}
