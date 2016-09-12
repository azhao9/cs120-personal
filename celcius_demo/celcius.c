/* celcius.c
 * A program for CS 120, fall 16
 * designed to print a conversion table for temperatures
 *
 * Author: Aleck Zhao
 * Date: 2016-09-12
 */

#include <stdio.h>

/* 
 * C = (F - 32) * 5 / 9
 * F = (C * 9 / 5) + 32
 */
int main()
{
	float tempFrom;
	float tempTo;

	int tempLow = 30;
	int tempHigh = 35;
	int stepSize = 1;
	
	tempFrom = tempLow;
	while (tempFrom <= tempHigh) {
		tempTo = (tempFrom - 32) * (5.0 / 9.0); // convert from F to C
		printf("%f F = %f C\n", tempFrom, tempTo);
		tempFrom = tempFrom + stepSize;
	}

	return 0;
}


