#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x)
{
	return (x - 5) * (x - 5);
}

double find_min(double a, double b, double eps)
{
	const int N = 100000;
	int i;
	double x1;//
	double x2;
	
	for(i = 0; i < N; i++)
	{
		if (b - a < eps) 
		{
			printf("result:   %.15f", (a + b) / 2.0);
			return ((a + b) / 2.0);
		}
		x1 = a + ((3 - sqrt(5)) / 2.0) * (b - a);
		x2 = a + ((-1 + sqrt(5)) / 2.0) * (b - a);
		if (func(x1) < func(x2))
			b = x2;
		else 
			a = x1;
	}
	printf("No, result");
	return 0.0;
}

int main()
{
	find_min(-10.0, 10.0, 0.00001);
	return 0;
}