#include <stdio.h>
#define LENGTH 5

int main() {
	
	int ra[LENGTH];

	printf("Enter 5 integers\n");

	scanf("%d %d %d %d %d", &(ra[0]), &(ra[1]), &(ra[2]), &(ra[3]), &(ra[4]));

	int sum = 0;

	for (int i = 0; i < LENGTH; i++) {
		sum += ra[i];
	}

	float avg = (float)sum/LENGTH;

	printf("The average is %f\n", avg);

	printf("The elements greater than the average are: ");

	for (int i = 0; i < LENGTH; i++) {
		if (ra[i] > avg) {
			printf("%d, ", ra[i]);
		}
	}
	printf("\n");
		
	return 0;


}

