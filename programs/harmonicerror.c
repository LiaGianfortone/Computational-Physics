#include <stdio.h>
#include <math.h>
#define type double

int main ()
{
	double doubleSumUp[6];
	double doubleSumDown[6];
	float singleSumUp[6];
	float singleSumDown[6];
	double errorUp[6];
	double errorDown[6];
	
	for (int p = 2; p < 8; p++)
	{
		int N = (int)pow(10, p);

		for (int n = 1; n <= N; n++)
		{
			doubleSumUp[p-2] += (double)pow(n, -1);
		}

		for (int n = N; n > 0; n--)
		{
			doubleSumDown[p-2] += (double)pow(n, -1);
		}
		printf("N=10^%d\tup: %e\tdown: %e\n", p, doubleSumUp[p-2], doubleSumDown[p-2]);
	}

	for (int p = 2; p < 8; p++)
	{
		int N = (int)pow(10, p);

		for (float n = 1; n <= N; n++)
		{
			singleSumUp[p-2] += (1.0 / n);
		}

		for (float n = N; n > 0; n--)
		{
			singleSumDown[p-2] += (1.0 / n);
		}
		printf("N=10^%d\tup: %e\tdown: %e\n", p, singleSumUp[p-2], singleSumDown[p-2]);
	}

	printf("N\tUp error\t\tDown error\n");
	for (int i = 0; i < 6; i++)
	{
		double errorUp = ((double)singleSumUp[i] - doubleSumUp[i]) / doubleSumUp[i];
		double errorDown = ((double)singleSumDown[i] - doubleSumDown[i]) / doubleSumDown[i];
		printf("N=10^%d\t%f\t%f\n", i+2, errorUp, errorDown);
	}
	return 0;
}