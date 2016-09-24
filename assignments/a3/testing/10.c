#include <stdio.h>

int main() {
	int sum = 0;
	int cur;

	printf("Enter integers:\n");
	int scan = scanf("%d", &cur);

	while (scan > 0) {
		sum += cur;

		scan = scanf("%d", &cur);

	}

	printf("\nSum: %d\n", sum);

	return 0;
}
