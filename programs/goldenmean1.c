#include <stdio.h>
#include <math.h>
#define N 6
double nth_phi (int n, double phi);
int main () {
	double phi = (sqrt((double) 5) - 1) / 2;
	for (int n = 1; n < N; n++) {
		printf("phi^%d = %f\n", n, nth_phi(n, phi));
	}
}
double nth_phi (int n, double phi) {	
	// assumes n > 0
	if (n == 1) {
		return phi;
	}
	return phi * nth_phi(--n, phi);
}