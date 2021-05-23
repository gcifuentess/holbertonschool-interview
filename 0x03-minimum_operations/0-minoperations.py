#!/usr/bin/python3
'''Min operations module'''


def minOperations(n):
    '''calculates the fewest number of operations needed to result in exactly
    n H characters in the file
    Args:
        n: any int number
    Return: Returns an integer, if n is impossible to achieve, return 0
    '''
    if type(n) is not int or n < 2:
        return 0
    string = "H"
    oper = 0
    p_factors = prime_factors(n)
    for factor in reversed(p_factors):
        if factor == 1:
            return oper
        for n_paste in range(factor):
            if n_paste == 0:
                copy = string  # copy all
            else:
                string += copy  # paste
            oper += 1


def prime_factors(n):
    '''Finds out the prime factors of a positive integer
    Args:
        n: a positive integer
    Returns: a list with the prime factors of n
    '''
    i = 2
    prime_factors = [1]
    while i <= n:
        if n % i == 0:
            prime_factors.append(i)
            n /= i
            i = 1
        i += 1
    return prime_factors
