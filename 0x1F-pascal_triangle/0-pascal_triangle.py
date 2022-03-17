#!/usr/bin/python3
'''Pascals Triangle'''


def pascal_triangle(n):
    '''returns a list of lists of integers representing the Pascal’s
       triangle of n

    Returns an empty list if n <= 0
    You can assume n will be always an integer
    '''
    pascal = [[1]]
    for _ in range(n - 1):
        pascal += [[1] + [pascal[-1][i] + pascal[-1][i + 1]
                   for i in range(len(pascal[-1]) - 1)] + [1]]
    return pascal if n > 0 else []
