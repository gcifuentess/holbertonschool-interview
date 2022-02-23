#!/usr/bin/python3
'''Island Permimeter Module'''


def island_perimeter(grid):
    '''Calculates the perimieter of an island in grid if any'''
    len_row = len(grid)
    len_col = len(grid[0])
    perimeter = 0
    i = 0
    while i < len_row:
        j = 0
        while j < len_col:
            cell = grid[i][j]
            if cell == 1:
                if i == 0 or grid[i - 1][j] == 0:  # checks upside
                    perimeter += 1
                if i == len_row - 1 or grid[i + 1][j] == 0:  # checks downside
                    perimeter += 1
                if j == 0 or grid[i][j - 1] == 0:  # checks leftside
                    perimeter += 1
                if j == len_col - 1 or grid[i][j + 1] == 0:  # checks rigthside
                    perimeter += 1
            j += 1
        i += 1
    return perimeter
