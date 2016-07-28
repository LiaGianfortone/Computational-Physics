#include <stdio.h>
#include <math.h>
#define type float
int main () {
	type x, delta;
	type epsilon = 1;
	while (x != 1) {
		delta = epsilon;
		epsilon /= 2;
		x = 1 + epsilon;
	}
	printf("Single precision: %.0e\n", delta);
	return 0;
}

	