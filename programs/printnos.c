#include <stdio.h>
#include <math.h>
int main () {
	printf("%.1e\n\n", 19000000.);

	double phi = (sqrt((double) 5) - 1) / 2;
	printf("The value of the golden mean is %.8f\n", phi); 
	return 0;
}

