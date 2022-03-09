#include "holberton.h"

/**
 * wildcmp - compares two strings
 *
 * @s1: the base string
 * @s2: the string to be found, can contain the special
 *      character *
 *
 * Important: The special char * can replace any string
 *            (including an empty string)
 *
 * Return: 1 if the strings can be considered identical,
 *         otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	if (!*s1)
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));

		return (!*s2);
	}

	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));

	if (*s1 != *s2)
		return (0);

	return (wildcmp(s1 + 1, s2 + 1));
}
