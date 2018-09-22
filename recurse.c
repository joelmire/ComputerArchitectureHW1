#include <stdio.h>
#include <stdlib.h>

int fn(int i);

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	printf("%d", fn(n));
	return EXIT_SUCCESS;
}

int fn(int i) {
	if (i == 0) {
		return 2;
	}
	if (i == 1) {
		return 3;
	}
	return 3 * fn(i - 2) + fn(i - 1) + 1;
}