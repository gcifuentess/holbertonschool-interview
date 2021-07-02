#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers
 * @size: the size of the array
 * @direction: thee direction to slide & merge (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	int start, end, step;

	if (!line || size == 0)
		return (0);

	/* bulding the parameters to slide and merge: */
	if (direction == SLIDE_LEFT)
	{
		step = 1;
		start = 0;
		end = size;
	}
	else if (direction == SLIDE_RIGHT)
	{
		step = -1;
		start = size - 1;
		end = -1;
	}
	else
	{
		return (0);
	}

	slide_and_merge(line, start, end, step);

	return (1);
}

/**
 * slide_and_merge - slides and merges an array of integers
 *                   depending on slide_line()
 * @line: points to an array of integers
 * @start: the idx of line where to start the slide
 * @end: the idx of line where to end the slide
 * @step: idx movement 1 to the right -1 to the left when merging
 *
 * Return: 1 on success, 0 on failure
 */

void slide_and_merge(int *line, int start, int end, int step)
{
	int i, current, next, idx;

	current = line[start];
	next = 0;
	idx = start;
	for (i = start + step; i != end; i += step)
	{
		if (!current)
		{
			current = line[i];
			line[i] = 0;
			line[idx] = current; /* sliding */
			continue;
		}
		next = line[i];
		line[i] = 0;
		if (!next)
			continue;
		if (current == next)
		{
			line[idx] = current + next; /* merging */
			current = 0;
		}
		else
		{
			current = next;
			line[idx + step] = current; /* sliding */
		}
		idx += step;
	}
}
