class Solution:
    def countZeroes(self, A, N):
        row, col = 0, N - 1
        count = 0

        while row < N and col >= 0:
            if A[row][col] == 0:
                count += col + 1
                row += 1
            else:
                col -= 1

        return count

matrix = [
    [0, 0, 0],
    [0, 0, 1],
    [0, 1, 1]
]
N = len(matrix)
sol = Solution()
result = sol.countZeroes(matrix, N)
print("Number of zeroes:", result) 