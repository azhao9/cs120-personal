/*
 * part3.c
 * Executes a loop
 *
 * author: Aleck Zhao
 * Date: 9/14/2016
 */

#include <stdio.h>

int main() {
	
	int num = 1;
	int val = 1;

	while (num < 6)
	{
		num = num + 1;
		val = val * num;
		
		printf("%d\n", num);
		printf("%d\n", val);
	}

	return 0;	
}


