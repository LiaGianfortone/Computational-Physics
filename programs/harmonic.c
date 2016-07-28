#include <stdio.h>
#include <math.h>
#define type float
int main () {
	printf("N\tSum_up\t\tSum_down\tSum_up - Sum_down\n");
	for (int p = 2; p < 8; p++) {
		int N = (int)pow(10, p);

		type sumUp = 0;
		for (int n = 1; n <= N; n++) {
			sumUp += pow(n, -1);
		}

		type sumDown = 0;
		for (int n = N; n > 0; n--) {
			sumDown += pow(n, -1);
		}
		type error = sumDown - sumUp;
		printf("10^%d\t%f\t%f\t%.4e\n", p, sumUp, sumDown, error);
	}
	return 0;
}