#!/usr/bin/python3
"""
Main file for testing
"""

makeChange = __import__('0-making_change').makeChange

print(makeChange([1, 2, 25], 37))

print(makeChange([1256, 54, 48, 16, 102], 1453))

print(makeChange([5, 10, 12, 2, 13, 11, 6, 1, 2, 8], 8))

print(makeChange([991, 993, 997, 999, 998, 996, 995, 1, 994, 992],
                 1000))

print(makeChange([], 1))

print(makeChange(1, 1))

print(makeChange([1, 2, 3, 4, 5, 6, 7, 8, 9], 45))
