#include <stdio.h>
#include <math.h>
#define type float
int main () {
	type x = 1;
	type y;
	int i = 0;
	while (x > 0 && isfinite(x)) {
		y = x;
		x /= 10;
		i -= 1;
	}
	printf("Smallest representable float: 2^%d=%.2g\n", i, y/9);
	return 0;
}

	