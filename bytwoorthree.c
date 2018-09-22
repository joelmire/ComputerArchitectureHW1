#include <stdio.h>
#include <stdlib.h>

/* prints out the first N positive numbers that
   are divisible by either 2 or 3 */

int main(int argc, char *argv[]) {
	int n;
	n = atoi(*argv[]);
	int* numbers_ptr;
	numbers_ptr = (int *)malloc(sizeof(int) * n);

    int i = 1;
	while(n > 0) {
		if (i % 2 == 0 || i % 3 == 0) {
			numbers_ptr[i - 1] = i;
			++i;
			--n;
		}
	}

	for (int k = 0; k < n; ++k) {
		printf("%d\n", numbers_ptr[k]);
	}
	
	return EXIT_SUCCESS;
}
