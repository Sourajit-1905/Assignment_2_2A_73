MAX = 100
 
def isSparseMatrix(array,m, n) :
    
    count = 0

    for i in range(0,m) :
        for j in range(0,n) :
            if (array[i][j] == 0) :
                count = count + 1
 
    return (count > 
            ((m * n) // 2))

array = [ [ 1, 0, 3 ],
          [ 0, 0, 4 ],
          [ 6, 0, 0 ] ]
m = 3
n = 3

if (isSparseMatrix(array, m, n)) :
    print("Yes")
else :
    print("No")
