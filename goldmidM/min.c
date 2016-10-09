#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x)
{
	return sin(x);
}

double find_min(double a, double b, double eps)
{
	const int N = 100000;
	int i;
	double x1;//
	double x2;
	x1 = a + ((3 - sqrt(5)) / 2.0) * (b - a);
	x2 = a + ((-1 + sqrt(5)) / 2.0) * (b - a);
	for(i = 0; i < N; i++)
	{
		if (b - a < eps) 
		{
			printf("result:   %.15f", (a + b) / 2.0);
			return ((a + b) / 2.0);
		}
		if (func(x1) < func(x2))
		{
			
			b = x2;
			x2 = x1;
			x1 = a + ((3 - sqrt(5)) / 2.0) * (b - a);
		}	
		else 
		{
			a = x1;
			x1 = x2;
			x2 = x2 = a + ((-1 + sqrt(5)) / 2.0) * (b - a);
		}	
			
	}
	printf("No, result");
	return 0.0;
}

int main()
{
	find_min(-0.5, 0.5, 0.00001);
	return 0;
}