#include <stdio.h>
#include <math.h>
#define type int

int main ()
{
	type x = 1;
	type y;
	int i = 0;
	while (x > 0 && isfinite(x))
	{
		y = x;
		x *= 2;
		i += 1;
	}
	// y *= 1.999999;	// for float/double
	printf("%d\n", i);
	printf("%f\n", y + (y - 1));
	return 0;
}

	