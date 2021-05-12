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
    copy = string
    oper = 1
    opt_div = optimal_divisor(n)
    pos = len(opt_div) - 1
    while len(string) < n:
        if oper < opt_div[pos]:
            string = string + copy
        elif len(copy) == opt_div[pos]:
            string = string + copy
            if len(string) == opt_div[pos - 1]:
                pos -= 1
                copy = string
                oper += 1
        else:
            copy = string
        oper += 1
    return oper


def optimal_divisor(n):
    '''Finds out optimal divisor of a positive integer'''
    i = n - 1
    divisors = [n + 1]
    while i > 1:
        if n % i == 0:
            n = i
            i = n - 1
            divisors.append(n)
        else:
            i -= 1
    return divisors
