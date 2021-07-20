#!/usr/bin/python3
'''N Queens Problem'''


def backtracking(chessboard, row):
    '''backtracking application.
    Args:
        chessboard: actual state of the game.
        row: the row to backtrack
    '''

    # count the number of queens
    q = [row_.count(1) for row_ in chessboard].count(1)

    # When all the queens are set and the validation is True,
    # prints the solution
    if len(chessboard) == q:
        solution = []
        for row_ in range(q):
            for col in range(q):
                if chessboard[row_][col] == 1:
                    solution.append([row_, col])
        print(solution)
        return

    for column in range(len(chessboard)):
        # if validation is True, a new queen is set and start to test a new one
        if validation(chessboard, row, column):
            chessboard[row][column] = 1
            # for row_ in chessboard:
            #    print(row_)
            # print("End_board")
            backtracking(chessboard, row + 1)
            reset_chessboard(chessboard, len(chessboard), row)
            # print("===RESET===")
    # print("exit row:", row)


def validation(chessboard, row, column):
    '''validates current position to see if its available
       vs the queens already set on the columns to the left.
    Args:
        chessboard: actual state of the game.
        row: row to validate.
        column: column to validate.
    returns: True or False
    '''
    # validate left
    for i in range(row):
        for j in range(column + 1):
            if (chessboard[row][j] == 1 or  # validate row
                chessboard[i][column] == 1 or  # validate col
                (abs(i - row) == abs(j - column) and
                 chessboard[i][j] == 1)):  # validate diagonal
                return False

    # validate right (column now is not validated, not needed)
    for i in range(row):
        for j in range(column + 1, len(chessboard)):
            if (chessboard[row][j] == 1 or  # validate row
                (abs(i - row) == abs(j - column) and
                 chessboard[i][j] == 1)):  # validade diagonal
                return False

    return True


def reset_chessboard(chessboard, N, init):
    '''resets or creates the chessboard
    Args:
        chessboard: sets the game.
        N: the number of queens
        init: row from wich the board must be reseted
    Return: the reseted chessboard
    '''
    if chessboard == []:
        for i in range(N):
            row = []
            for j in range(N):
                row.append(0)
            chessboard.append(row)
    else:
        for i in range(init, N):
            for j in range(N):
                chessboard[i][j] = 0
    return chessboard


if __name__ == "__main__":
    import sys

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    N = 0
    try:
        N = int(sys.argv[1])
    except:
        print("N must be a number")
        sys.exit(1)
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Creation of the chessboard
    chessboard = []
    chessboard = reset_chessboard(chessboard, N, 0)

    # starts the seeking of the solution in the first row
    backtracking(chessboard, 0)
