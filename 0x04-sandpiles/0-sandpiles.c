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
			if (grid1[i][j] > 3)
				check = 'u';
		}
	}
	if (check == 'u')
	{
		printf("=\n");
		print_grid(grid1);
	}

	stabilize(grid1);
}

/**
 * stabilize - stabilizes a sandpile
 * @grid: a sandpile
 *
 * Return: 's' if stable or 'u' if not
 */
void stabilize(int grid[3][3])
{
	char check = 'u';
	int i, j;

	while (check == 'u')
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid[i][j] > 3)
				{
					grid[i][j] -= 4;
					if (j - 1 > -1)
						grid[i][j - 1] += 1;
					if (j + 1 < 3)
						grid[i][j + 1] += 1;
					if (i - 1 > -1)
						grid[i - 1][j] += 1;
					if (i + 1 < 3)
						grid[i + 1][j] += 1;
				}
				if (grid[i][j] <= 3)
					check = 's';
				else
					check = 'u';
			}
		}
		if (check == 'u')
		{
			printf("=\n");
			print_grid(grid);
		}

	}
	printf("\n%c", check);
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
