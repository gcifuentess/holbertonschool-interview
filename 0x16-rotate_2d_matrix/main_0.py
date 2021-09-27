#!/usr/bin/python3
"""
Test 0x16 - Rotate 2D Matrix
"""
rotate_2d_matrix = __import__('0-rotate_2d_matrix').rotate_2d_matrix

if __name__ == "__main__":
    matrix = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]

    # matrix = [[1, 2, 3],
    #           [4, 5, 6]]

    # matrix = [[1, 2],
    #           [4, 5],
    #           [7, 8]]

    # matrix = [[1, 2, 3, 10],
    #           [4, 5, 6, 11],
    #           [7, 8, 9, 12]]

    rotate_2d_matrix(matrix)
    print(matrix)
