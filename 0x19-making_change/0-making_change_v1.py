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

    if coins == [] or type(coins) is not list:
        return -1

    # to start looking from the biggest to lowest coin:
    rev_coins = coins
    rev_coins.sort(reverse=True)

    # The number of possible combinations between coins in the pile:
    n_combinations = (1 << (len(rev_coins) - 1)) - 1

    # Start to filter the set of coins for each combination
    for idxs in idx_list(n_combinations):

        if idxs == []:
            filtered_coins = rev_coins
        else:
            filtered_coins = rev_coins.copy()

            for idx in reversed(idxs):
                del filtered_coins[-idx]

        min_coins = find_min(filtered_coins, total)
        if min_coins != -1:
            break
    else:
        min_coins = -1

    return min_coins


def find_min(filtered_coins, total):
    """Given a filtered pile of coins of different values, determine the fewest
       number of coins needed to meet a given amount total.

    Args:
        coins is a list of the values of the filtered coins
        The value of a coin will always be an integer greater than 0
        You can assume you have an infinite number of each denomination of coin
        in the list

    Return: fewest number of coins needed to meet total
        If total cannot be met by any number of coins you have, return -1
    """
    acc = 0
    min_coins = 0
    for coin in filtered_coins:
        while True:
            if total >= (acc + coin):
                acc += coin
                min_coins += 1
            else:
                break

    if total == acc:
        return min_coins

    return -1


def idx_list(n_combinations):
    """Generates a list of lists with inverse indices needed to filter
     the pile of coins

    Args:
       n_combinations: is the number of posible combinations between coins
                       in the pile

    Return: a list of lists

    Example: idx_list(4)
             returns: [[], [1], [2], [1, 2]]

             The number of lists corresponds with the number of combinations
             (n_combinations).

            - The first list, means no element should be removed
            - The second list: the last element (idx -1) should be removed
            - The third list: only de penultimate element should be removed
            - and lastly: both elements (last & penultimate) should be removed
    """
    idxs = [[]]
    idx_count = 0
    base = 1

    for i in range(1, n_combinations + 1):

        if base % 1 == 0:  # if base of 2
            insert_idx = True
            idx_count += 1
            sub_idx = 1
        else:
            insert_idx = False

        if insert_idx:
            idxs.append([idx_count])
        else:
            idxs.append(idxs[sub_idx] + [idx_count])
            sub_idx += 1

        # to check if next i is a base of 2:
        base = (i + 1) ** (1 / idx_count)

    return idxs
