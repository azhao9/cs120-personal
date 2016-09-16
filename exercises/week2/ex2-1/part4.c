/*
 * part4.c
 * Reads in text 
 *
 * author: Aleck Zhao
 * Date: 9/14/2016
 */

#include <stdio.h>

int main() {
	
	int count = 0;

	while (count < 10) 
	{
		char input = getchar();
		printf("%c\n", input);
		count = count + 1;

	}	

	return 0;	
}


