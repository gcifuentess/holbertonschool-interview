#!/usr/bin/python3


def rain(walls):
    '''Given a list of non-negative integers representing the heights of walls
    with unit width 1, as if viewing the cross-section of a relief map,
    calculate how many square units of water will be retained after it rains.

    Args:
        walls is a list of non-negative integers.

    Return: Integer indicating total amount of rainwater retained.

    Important: Assume that the ends of the list (before index 0 and after
               index walls[-1]) are not walls, meaning they will not retain
               water.
    '''
    if (type(walls) is not list or walls == []):
        return 0

    len_walls = len(walls)

    if (len_walls < 3):
        return 0

    if (not all(x >= 0 for x in walls)):
        return 0

    left_tws = [0 for x in walls]
    left_tws[0] = walls[0]

    for i in range(1, len_walls):
        left_tws[i] = max(left_tws[i - 1], walls[i])

    water_r = 0
    right_twr = walls[-1]

    i = len_walls - 2
    while (i >= 0):
        water = min(left_tws[i], right_twr) - walls[i]
        right_twr = max(walls[i], right_twr)
        if (water > 0):
            water_r += water
        i -= 1

    return water_r
