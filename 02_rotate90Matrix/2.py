class Solution:
    def rotateMatrix(self, mat):
        n = len(mat)  
        
        for i in range(n):
            for j in range(i + 1, n):
                
                mat[i][j], mat[j][i] = mat[j][i], mat[i][j]
        for j in range(n):
            for i in range(n // 2):
                mat[i][j], mat[n - 1 - i][j] = mat[n - 1 - i][j], mat[i][j]

sol = Solution()
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

print("Original Matrix:")
for row in matrix:
    print(row)

sol.rotateMatrix(matrix)

print("\nRotated Counter-Clockwise Matrix:")
for row in matrix:
    print(row)
