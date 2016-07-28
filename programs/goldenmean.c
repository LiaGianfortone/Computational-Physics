#include <stdio.h>
#include <math.h>
#define N 50

double nth_phi (int n, double phi);

int main ()
{
	double phi = (sqrt((double) 5) - 1) / 2;
	double powsofphi[N];
	double powsOfPhi[N];
	int n;

	for (n = 1; n < N; n++)
	{
		printf("phi^%d = %f\n", n, nth_phi(n, phi));
	}

	powsOfPhi[0] = 1;
	for (n = 1; n < N; n++) 
	{
		powsOfPhi[n] = nth_phi(n, phi);
	}

	
	powsofphi[0] = 1;
	powsofphi[1] = phi;
	for (n = 2; n < N; n++)
	{
		powsofphi[n] = powsofphi[n-2] - powsofphi[n-1];
	}

	printf("n\tphi^n (1)\tphi^n (2)\n");
	for (n = 0; n < N; n++)
	{
		printf("%d\t%.4e\t%.4E\n", n, powsOfPhi[n], powsofphi[n]);
	}
	return 0;
}

double nth_phi (int n, double phi)
{	// assumes n > 0
	if (n == 1)
	{
		return phi;
	}
	return phi * nth_phi(--n, phi);
}