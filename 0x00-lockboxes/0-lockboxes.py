#!/usr/bin/python3
'''Unlock boxes module'''


def canUnlockAll(boxes):
    '''determines if all the boxes can be opened'''
    remaining = [x for x in range(1, len(boxes))]
    for key in boxes[0]:
        recursion(boxes, remaining, key)
    if len(remaining) == 0:
        return (True)
    else:
        return (False)


def recursion(boxes, remaining, key):
    '''dives into boxes'''
    if key not in remaining:
        return
    else:
        remaining.remove(key)
        for new_key in boxes[key]:
            recursion(boxes, remaining, new_key)
    return
