#include "main.h"

/**
 * factors - breaks numbers into factorials
 * Return: 0 (success)
 */
int factors(mytypedef_t n)
{
	mytypedef_t w = n / 2;
	mytypedef_t p;
	mytypedef_t q;

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
