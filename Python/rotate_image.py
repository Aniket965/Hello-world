import numpy as np

class Solution:
    def rotate(self, A):
        print("Starting Matrix")
        print(np.matrix(a))
        n = len(A)
        print("Starting Transpose")
        for i in range(n):
            for j in range(i):
                A[i][j], A[j][i] = A[j][i], A[i][j]
                print(np.matrix(A))
        print("Starting left-right flip")
        for row in A:
            for j in range(n//2):
                row[j], row[~j] = row[~j], row[j]
                print(np.matrix(A))
                print("j: ", j)
                print("~j: ", ~j)

test = Solution()

a = [
  [1,2,3],
  [4,5,6],
  [7,8,9]
]

test.rotate(a)
