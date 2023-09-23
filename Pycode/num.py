def solve_sudoku(board):
    def is_valid(num, row, col):
        for i in range(9):
            if board[i][col] == num:
                return False
            if board[row][i] == num:
                return False
            if board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == num:
                return False
        return True
    
    def recursion():
        for row in range(9):
            for col in range(9):
                if board[row][col] == 0: #等于0的部分才是需要填入的
                    for num in range(1, 10):
                        if is_valid(num, row, col):
                            board[row][col] = num
                            if recursion():
                                return True
                            board[row][col] = 0
                    return False
        return True
    
    recursion()



sudoku_board = [
    [5, 3, 0, 0, 7, 0, 0, 0, 0],
    [6, 0, 0, 1, 9, 5, 0, 0, 0],
    [0, 9, 8, 0, 0, 0, 0, 6, 0],
    [8, 0, 0, 0, 6, 0, 0, 0, 3],
    [4, 0, 0, 8, 5, 3, 0, 0, 1],
    [7, 0, 0, 0, 2, 0, 0, 0, 6],
    [9, 6, 0, 0, 0, 0, 2, 8, 0],
    [0, 0, 0, 4, 1, 9, 0, 0, 5],
    [0, 0, 0, 0, 8, 0, 0, 7, 9]
]

solve_sudoku(sudoku_board)

for i in range(9):
    print(sudoku_board[i])


# 可以根据python tutor网站进行分析，妙