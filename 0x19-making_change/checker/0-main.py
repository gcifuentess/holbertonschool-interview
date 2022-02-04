#!/usr/bin/python3
"""
Main file for testing - case: small total - possible (3 pts)
"""


import sys
import os
import inspect

currentdir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parentdir = os.path.dirname(currentdir)
sys.path.insert(0, parentdir)


makeChange = __import__('0-making_change').makeChange

print(makeChange([1, 2, 10], 11))  # asw: 2
