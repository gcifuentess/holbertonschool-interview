#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: the first sandpile
 * @grid2: the second sandpile
 *
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	char check = 's'; /* s for stable */

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			if (grid1[i][j] > 3 && check == 's')
				check = 'u';
		}
	}
	while (check == 'u')
	{
		printf("=\n");
		print_grid(grid1);
		stabilize(grid1);
		check = check_stability(grid1);
	}
}

/**
 * stabilize - stabilizes a sandpile
 * @grid: a sandpile
 *
 * Return: 's' if stable or 'u' if not
 */
void stabilize(int grid[3][3])
{
	int i, j;
	int tgrid[3][3] = {
		{-1, -1, -1},
		{-1, -1, -1},
		{-1, -1, -1}
	};

	/* copy the grid */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			tgrid[i][j] = grid[i][j];
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (tgrid[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (j - 1 >= 0)
					grid[i][j - 1] += 1;
				if (j + 1 <= 2)
					grid[i][j + 1] += 1;
				if (i - 1 >= 0)
					grid[i - 1][j] += 1;
				if (i + 1 <= 2)
					grid[i + 1][j] += 1;
			}
		}
	}
}


/**
 * check_stability - checks if every number of the grid is <= 3
 * @grid: a sandpile
 *
 * Return: 's' if stable or 'u' if not
 */
char check_stability(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return('u');
	return ('s');
}


/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
