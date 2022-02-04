#!/usr/bin/python3
"""makeChange module"""


def makeChange(coins, total):
    """Given a pile of coins of different values, determine the fewest number
       of coins needed to meet a given amount total.

    Args:
        coins is a list of the values of the coins in your possession
        The value of a coin will always be an integer greater than 0
        You can assume you have an infinite number of each denomination of coin
        in the list

    Return: fewest number of coins needed to meet total
        If total is 0 or less, return 0
        If total cannot be met by any number of coins you have, return -1
    """
    if total <= 0:
        return 0

    min_coins = 0
    remaining = total

    coins.sort(reverse=True)

    for coin in coins:
        factor = int(remaining / coin)
        remaining -= factor * coin
        min_coins += factor
        if remaining == 0:
            break

    if remaining > 0:
        return -1

    return min_coins
