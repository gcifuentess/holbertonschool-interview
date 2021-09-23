#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>

int _putchar(char c);
int _strlen(char *s);
void *_calloc(unsigned int nmemb, unsigned int size);

void check_arg(char *arg);
char *str_mult(char *s1, char *s2);
void sums_for_mult(int ls1, int ls2, char *result, char *temp);
void print_error(void);

#endif /* HOLBERTON_H */
