#!/usr/bin/python3
"""
Main file for testing - Runtime check - possible total
"""
import sys
import os
import inspect
import time


currentdir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parentdir = os.path.dirname(currentdir)
sys.path.insert(0, parentdir)


makeChange = __import__('0-making_change').makeChange

start = time.time()

for i in range(10):
    makeChange([1, 4, 5, 10], 1278652)

end = time.time()

avg = (end - start) / 10

if avg > 3:
    print("Runtime too long")
else:
    print("OK")
