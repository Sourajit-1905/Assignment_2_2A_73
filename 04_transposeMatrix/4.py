class Solution:
    def transpose(self, mat):
        n = len(mat)
        ans = [[0] * n for _ in range(n)]  

        for i in range(n):
            for j in range(n):
                ans[i][j] = mat[j][i]  

        return ans
    
sol = Solution()
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

print("Original Matrix:")
for row in matrix:
    print(row)

transposed = sol.transpose(matrix)

print("\nTransposed Matrix:")
for row in transposed:
    print(row)