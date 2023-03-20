#include "main.h"
#include "math.h"
/**
 * factors - breaks numbers into factorials
 * Return: 0 (success)
 */

int factors(unsigned long long n)
{
	unsigned long long w = sqrt(n);
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
	printf("%llu=%llu*%llu\n", n, q, p);
	return 0;
}
