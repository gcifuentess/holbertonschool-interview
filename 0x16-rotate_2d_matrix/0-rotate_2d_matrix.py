#!/usr/bin/python3
'''Rotate 2D Matrix'''


def rotate_2d_matrix(matrix):
    '''Given an n x n 2D matrix, rotate it 90 degrees clockwise
    Args:
        matrix is a 2D matrix. Lists into lists

    Important: It is assumed the matrix will have 2 dimensions and will not be
               empty.

    Returns: Nothing. The matrix is edited in-place
    '''
    bk = [row.copy() for row in matrix]
    rows = len(matrix)
    columns = len(matrix[0])

    # add rows and remove columns:
    if rows < columns:
        for i in range(rows):
            for j in range(columns - rows):
                matrix[i].pop()
        for i in range(columns - rows):
            matrix.append(matrix[0].copy())

    # add columns and remove rows:
    elif columns < rows:
        for i in range(rows):
            for j in range(rows - columns):
                matrix[i].append(0)
        for i in range(rows - columnsxo):
            matrix.pop()

    for i in range(columns):
        inv_i = rows
        for j in range(rows):
            inv_i -= 1
            matrix[i][j] = bk[inv_i][i]
