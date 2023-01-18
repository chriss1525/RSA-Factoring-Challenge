#include "main.h"

/**
 * main - finds the factors of a number
 * @argc: count of arguments
 * @argv: arguments passed
 * @Return: 0 (fail) 1 (success)
 */

int main(int argc, char **argv)
{
    int *n;
    FILE *str;

    if (argc != 2)
        return(EXIT_FAILURE);

    n = malloc(512);
    str = fopen(argv[1], "r");

    while (fscanf(str, "%d", n) == 1)
        factors(*n);

    return (0);
}
