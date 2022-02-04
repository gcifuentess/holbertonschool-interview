#!/usr/bin/python3
"""
Main file for testing - case: 0 total (1 pts)
"""
import sys
import os
import inspect


currentdir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parentdir = os.path.dirname(currentdir)
sys.path.insert(0, parentdir)


makeChange = __import__('0-making_change').makeChange

print(makeChange([10, 25, 50], 0))  # asw: 0
