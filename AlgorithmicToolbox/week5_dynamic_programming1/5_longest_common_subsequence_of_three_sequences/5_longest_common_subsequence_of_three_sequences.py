#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3
import numpy as np
"""
Compute the length of a longest common subsequence of two sequences.
This extends the previous problem of two subsequneces.
"""
def lcs3(first_sequence, second_sequence, third_sequence):
    assert len(first_sequence) <= 100
    assert len(second_sequence) <= 100
    assert len(third_sequence) <= 100

    A, B, C = first_sequence, second_sequence, third_sequence
    D = np.empty((len(A)+1, len(B)+1, len(C)+1))
    
    for i in range(len(A)+1):
        for j in range(len(B)+1):
            D[i][j][0] = 0
    for j in range(len(B)+1):
        for k in range(len(C)+1):
            D[0][j][k] = 0
    for k in range(len(C)+1):
        for i in range(len(A)+1):
            D[i][0][k] = 0
    
    for i in range(1, len(A)+1):
        for j in range(1, len(B)+1):
            for k in range(1, len(C)+1):
                if A[i-1] == B[j-1] and A[i-1] == C[k-1]:
                    D[i][j][k] = 1 + D[i-1][j-1][k-1]
                else:
                    D[i][j][k] = max(D[i-1][j][k], D[i][j-1][k], D[i][j][k-1])
    
    return int(D[len(A)][len(B)][len(c)])


if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    assert len(a) == n

    m = int(input())
    b = list(map(int, input().split()))
    assert len(b) == m

    q = int(input())
    c = list(map(int, input().split()))
    assert len(c) == q

    print(lcs3(a, b, c))


# In[ ]:




