#include <stdio.h>
#include <math.h>

int main () {
	int x = 1;
	int y;
	int i = 0;
	while (x > 0 && isfinite(x)) {
		y = x;
		x *= 2;
		i += 1;
	}
	printf("Bits in a signed int: %d\n", i + 1);
	printf("Largest representable int: 2^%d=%d\n", i, y + (y - 1));
	return 0;
}

	