#include "main.h"
#include "math.h"
#include <gmp.h>
/**
 * factors - breaks numbers into factorials
 * Return: 0 (success)
 */

int is_prime(mpz_t n)
{
	if (mpz_cmp_ui(n, 1) <= 0)
	{
		return 0;
	}

	mpz_t i, q;
	mpz_init(i);
	mpz_set_ui(i, 2);

	while (mpz_cmp(i, q) <= 0)
	{
		if (mpz_cmp_ui(q, 2) < 0)
		{
			mpz_clear(i);
			mpz_clear(q);
			return 0;
		}
		if (mpz_cmp_ui(q, 2) == 0)
		{
			mpz_clear(i);
			mpz_clear(q);
			return 1;
		}
		mpz_sqrt(q, n);
		if (mpz_divisible_p(n, q))
		{
			mpz_clear(i);
			mpz_clear(q);
			return 0;
		}
		mpz_add_ui(i, i, 1);
		mpz_fdiv_q(q, n, i);
	}

	mpz_clear(i);
	mpz_clear(q);
	return 1;
}


void factorize(mpz_t n)
{
	mpz_t i, q;
	mpz_inits(i, q, NULL);
	mpz_set_ui(i, 2);
	mpz_cdiv_q(q, n, i);

	while (mpz_cmp(i, q) <= 0)
	{
		if (mpz_divisible_p(n, i))
		{
			mpz_cdiv_q(q, n, i);
			if (is_prime(i) && is_prime(q))
			{
				gmp_printf("%Zd=%Zd*%Zd\n", n, i, q);
				mpz_clears(i, q, NULL);
				return;
			}
		}
		mpz_add_ui(i, i, 1);
		mpz_cdiv_q(q, n, i);
	}

	gmp_printf("%Zd is prime\n", n);
	mpz_clears(i, q, NULL);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: factors natural numbers \n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error opening file\n");
		return 1;
	}

	mpz_t n;
	mpz_init(n);

	while (gmp_fscanf(fp, "%Zd", n) == 1)
	{
		factorize(n);
	}

	mpz_clear(n);
	fclose(fp);
	return 0;
}
