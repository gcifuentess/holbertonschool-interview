#include "holberton.h"

/**
 * main - multiplies two large numbers
 * @ac: counts the number of arguments. Always >= 0.
 * @av: array with the strings of the names of the arguments
 *
 * Return: 1 if success, exit code 98 on failure
 */

int main(int ac, char **av)
{
	char *result;
	int i, len;

	if (ac != 3)
		print_error();

	check_arg(av[1]);
	check_arg(av[2]);
	result = str_mult(av[1], av[2]);
	len = _strlen(result);
	for (i = 0; i < len; i++)
	{
		if (result[i] == '0' && i == 0)
		{
			while (result[i + 1] == '0')
				i++;

			if (i == len - 1)
				_putchar('0');
		}
		else
			_putchar(result[i]);
	}
	_putchar('\n');
	free(result);
	return (0);
}


/**
 * check_arg - checks arg for non-digits
 * @arg: the argument to be checked
 *
 * Return: Nothing
 */
void check_arg(char *arg)
{
	int i, len;

	len = _strlen(arg);
	for (i = 0; i < len; i++)
	{
		if (arg[i] < 48 || arg[i] > 57)
			print_error();
	}
}


/**
 * str_mult - multiplies two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: retult string
 */
char *str_mult(char *s1, char *s2)
{
	char *mult, *result, *temp;
	int ls1, ls2, i, j, k = 0, x = 0, y;
	long int r = 0;

	ls1 = _strlen(s1) - 1;
	ls2 = _strlen(s2) - 1;
	mult = _calloc(ls1 + ls2 + 5, 1);
	result = _calloc(ls1 + ls2 + 5, 1);
	temp = _calloc(ls1 + ls2 + 90000000, 1);

	for (i = 0; i <= ls1; i++)
		s1[i] = s1[i] - 48;
	for (i = 0; i <= ls2; i++)
		s2[i] = s2[i] - 48;
	for (i = ls2; i >= 0; i--, r = 0)
	{
		for (j = ls1; j >= 0; j--)
		{
			temp[k++] = (s2[i] * s1[j] + r) % 10;
			r = (s2[i] * s1[j] + r) / 10;
		}
		temp[k++] = r;
		x++;
		for (y = 0; y < x; y++)
			temp[k++] = 0;
	}

	sums_for_mult(ls1, ls2, result, temp);

	for (i = ls1 + ls2 + 1, j = 0; i >= 0; i--, j++)
		mult[j] = result[i] + 48;

	mult[j] = '\0';
	free(result);
	free(temp);

	return ((void *)mult);
}


/**
 * sums_for_mult - performs the sumations for the multiplication
 * @ls1: len of the first string (without last null value)
 * @ls2: len of the second string (without last null value)
 * @result: pointer of the allocated memory to store the results
 * @temp: pointe of the allocated memory to store temporally the results
 *
 * Return: Nothing
 */
void sums_for_mult(int ls1, int ls2, char *result, char *temp)
{
	int i, k, j, pos;
	long int r;
	long sum;

	for (i = 0, k = 0, r = 0; i < ls1 + ls2 + 2; i++)
	{
		for (j = 1, sum = 0, pos = 0; j <= ls2 + 1; j++)
		{
			if (i <= ls1 + j)
				sum = sum + temp[pos + i];
			pos += j + ls1 + 1;
		}
		result[k++] = (sum + r) % 10;
		r = (sum + r) / 10;
	}
	result[k] = r;
}

/**
 * print_error - prints the error and exit 98
 *
 * Return: Nothing
 */
void print_error(void)
{
	int i, len;
	char *error;

	error = "Error\n";
	len = _strlen(error);
	for (i = 0; i < len; i++)
	{
		_putchar(error[i]);
	}
	exit(98);
}
