#!/usr/bin/python3
"""
Main file for testing - case: long list of coins
"""
import sys
import os
import inspect


currentdir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parentdir = os.path.dirname(currentdir)
sys.path.insert(0, parentdir)


makeChange = __import__('0-making_change').makeChange

coins = []
for i in range(1, 1000, 7):
    coins.append(i)
print(makeChange(coins, 16576)) # asw: 21
