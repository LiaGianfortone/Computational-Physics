#include <stdio.h>
#include <math.h>
#define N 50
int main () {
	double phi = (sqrt((double) 5) - 1) / 2;
	double powsofphi[N];
	powsofphi[0] = 1;
	powsofphi[1] = phi;
	for (int n = 2; n <= N; n++) {
		powsofphi[n] = powsofphi[n-2] - powsofphi[n-1];
		printf("phi^%d:\t%e\n", n, powsofphi[n]);
	}
	return 0;
}
