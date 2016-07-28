#include <stdio.h>
#include <math.h>
#define type float
#define M 6
int main () {
	double doubleup[M] = {0};
	double doubledown[M] = {0};
	float singleup[M] = {0};
	float singledown[M] = {0};
	double uperror[M] = {0};
	double downerror[M] = {0};

	for (int p = 2; p < 8; p++) {
		int N = (int)pow(10, p);
		for (int n = 1; n <= N; n++) {
			doubleup[p-2] += pow(n, -1);
			singleup[p-2] += pow(n, -1);
		}
		type sumDown = 0;
		for (int n = N; n > 0; n--) {
			doubledown[p-2] += pow(n, -1);
			singledown[p-2] += pow(n, -1);
		}
		

		uperror[p-2] = (singleup[p-2] - doubleup[p-2]) / doubleup[p-2];
		downerror[p-2] = (singledown[p-2] - doubledown[p-2]) / doubledown[p-2];
		printf("N=10^%d\tup_error: %.3e\tdown_error: %.3e\n", p, uperror[p-2], downerror[p-2]);
	}
	/*
	for (int i = 0; i < M; i++)
	{
		printf("\t1_up: %.3e\t\t2_up: %.3e\t\t1_dwn: %.3e\t2_dwn: %.3e\n", singleup[i], doubleup[i], singledown[i], doubledown[i]);
	}
	return 0;
	*/
}