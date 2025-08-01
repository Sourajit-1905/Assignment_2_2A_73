def check_identity(mat):
    size = len(mat)
    for row in range(size):
        if mat[row][row] != 1:
            return False
        for col in range(size):
            if row != col and mat[row][col] != 0:
                return False
    return True

matrix = [
    [1, 0, 0],
    [0, 1, 0],
    [0, 0, 1]
]

if check_identity(matrix):
    print("Valid Identity Matrix")
else:
    print("Not an Identity Matrix")