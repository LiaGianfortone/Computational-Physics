#include <stdio.h>
#include <math.h>
#define type double
type f (type x) {
	return (1 / x);
}
type d2fdx2 (type x, type h) {
	return ((f(x+h)+f(x-h)-2*f(x)) / (h*h));
}
int main () {
	type x = 1;
	for (type h = 0.1; h > 0.00001; h /= 10) {
		printf("h: %f\tf\"(%g): %.7f\n", 
				h, x, d2fdx2(x, h));
	}
	return 0;
}