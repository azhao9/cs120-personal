/*
 * Filename: a2_v1.c
 * Purpose: Reads character inputs and prints them
 * Authors: Noah Halpern & Aleck Zhao
 * Date Created: 9.14.2016
 * Date Modified: 9.14.2016
 */

#include <stdio.h>

int main(){
    
    char in = getchar();

    while(in != EOF){
        
        
        printf("%c", in);
        in = getchar();

    }

    return 0;

}
