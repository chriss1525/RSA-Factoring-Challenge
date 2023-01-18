#include "main.h"

/**
 * factors - breaks numbers into factorials
 * Return: 0 (success)
 */
int factors(unsigned long long n)
{
	unsigned long long w = n / 2;
	unsigned long long p;
	unsigned long long q;
	
	for (q = 2; q <= w; q++)
	{
		if (n % q == 0)
		{
			p = n / q;
			break;
		}
	}
	printf("%llu=%llu*%llu\n", n, p, q);
	return (0);
}
