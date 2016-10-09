#include <stdio.h>
#include <stdlib.h>

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
	double c;//mid
	double delta = 0.00000001;//+- delta
	
	for(i = 0; i < N; i++)
	{
		if (b - a < eps) 
		{
			printf("result:   %.15f", a + b / 2.0);
			return (a + b / 2.0);
		}
		c = (b + a) / 2.0;
		x1 = c - delta;
		x2 = c + delta;
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
	find_min(-10.0, 10.0, 0.000001);
	return 0;
}