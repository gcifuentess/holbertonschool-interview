#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: is the level of the Menger Sponge to draw
 *
 * Return: Nothing
 */
void menger(int level)
{
	char **sponge;
	int sponge_size, i;

	if (level < 0)
		return;

	if (level == 0)
	{
		printf("#\n");
		return;
	}

	sponge = menger_recursive(level);
	sponge_size = pow(3, level);

	/* print the sponge */
	for (i = 0; i < sponge_size; i++)
		printf("%s\n", sponge[i]);

	free(sponge);
}

/**
 * menger_recursive - allocates the memory for the Sponge
 * @level: is the level of the Menger Sponge
 *
 * Return: Sponge double pointer
 */
char **menger_recursive(int level)
{
	char **sponge, **sponge_prev;
	int sponge_size, sponge_prev_size, len;

	sponge_size = pow(3, level);

	/* Calculate the total number of bites of the 2D matrix */
	len = sizeof(char *) * sponge_size;
	len += sizeof(char) * pow(sponge_size + 1, 2);

	/* Allocate the hole 2D matrix */
	sponge = (char **)calloc(1, len);
	if (!sponge)
		exit(1);

	/* base case, level 0 */
	if (level == 0)
	{
		sponge[0] = (char *)(sponge + sponge_size);
		strcpy(sponge[0], "#");
		return (sponge);
	}

	/* to build the sponge, the level - 1 sponge is used */
	sponge_prev = menger_recursive(level - 1);
	sponge_prev_size = sponge_size / 3;

	return (sponge_builder(sponge, sponge_size,
			       sponge_prev, sponge_prev_size));

}

/**
 * soponge_builder - fills the Sponge
 * @sponge: double pointer to the allocated memory for the Sponge
 * @sponge_size: int of the hight or width of the Sponge
 * @sponge_prev: double pointer to the Sponge on level - 1
 * @sponge_prev_size: int of hight (width) of the Sponge on level - 1
 *
 * Return: Sponge double pointer filled
 */
char **sponge_builder(char **sponge, int sponge_size,
		      char **sponge_prev, int sponge_prev_size)
{

	char *ptr, *line, *line2, *spaces;
	int i, j, k;

	line = "###";
	line2 = "# #";
	spaces = "   ";

	/* first line pointer */
	ptr = (char *)(sponge + sponge_size);

	/* populate the 2D matrix, the sponge */
	for (i = 0; i < sponge_prev_size; i++)
	{
		/* Asign each line pointer to the rows of the 2D matrix */
		for (k = 0; k < 3; k++)
			sponge[i * 3 + k] = (ptr + (sponge_size + 1) *
					     (i * 3 + k));
		for (j = 0; j < sponge_prev_size; j++)
		{
			if (sponge_prev[i][j] == '#')
			{
				strcat(sponge[i * 3], line);
				strcat(sponge[i * 3 + 1], line2);
				strcat(sponge[i * 3 + 2], line);
			}
			else if (sponge_prev[i][j] == ' ')
			{
				strcat(sponge[i * 3], spaces);
				strcat(sponge[i * 3 + 1], spaces);
				strcat(sponge[i * 3 + 2], spaces);
			}
		}
	}
	free(sponge_prev);
	return (sponge);
}
