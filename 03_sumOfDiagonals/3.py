from typing import List
class Solution:
    def sumDiagonal(self, N : int , M : List[List[int]] ) -> int :
        diagSum = 0
        for i in range(0, N): 
            diagSum += M[i][i]
            
        return diagSum
    
sol = Solution()
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
print("Sum of diagonal:", sol.sumDiagonal(3, matrix))
