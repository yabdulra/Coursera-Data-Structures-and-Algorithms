#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3
import numpy as np

"""
Compute the length of a longest common subsequence of two sequences.
Example: a common subsequence between [2 7 8 3] and [5 2 8 7] is (2, 7)
another one is (2, 8), so the program should return 2 i.e the number of
common subsequence.
"""

def lcs2(first_sequence, second_sequence):
    assert len(first_sequence) <= 100
    assert len(second_sequence) <= 100
    
    A, B = first_sequence, second_sequence
    D = np.zeros((len(A)+1, len(B)+1))
    
    for i in range(len(A)+1):
        D[i][0] = 0
    for j in range(len(B)+1):
        D[0][j] = 0
    
    for i in range(1, len(A)+1):
        for j in range(1, len(B)+1):
            if A[i-1] == B[j-1]:
                D[i][j] = 1 + D[i-1][j-1]
            else:
                D[i][j] = max(D[i][j-1], D[i-1][j])
    
    return int(D[len(A)][len(B)])


if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    assert len(a) == n

    m = int(input())
    b = list(map(int, input().split()))
    assert len(b) == m

    print(lcs2(a, b))


# In[ ]:




