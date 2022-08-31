#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3
import numpy as np

"""
The edit distance between two strings is the minimum number of operations (insertions, deletions,
and substitutions of symbols) to transform one string into another. It is a measure of similarity
of two strings. Edit distance has applications, for example, in computational biology, natural 
language processing, and spell checking. Your goal in this problem is to compute the edit distance
between two strings.
"""

def edit_distance(first_string, second_string):
    
    A, B = first_string, second_string
    
    D = np.zeros((len(A)+1, len(B)+1))
    
    for i in range(len(A)+1):
        D[i][0] = i
    for j in range(len(B)+1):
        D[0][j] = j
    
    for j in range(1, len(B)+1):
        for i in range(1, len(A)+1):
            insertion = D[i][j-1] + 1
            deletion = D[i-1][j] + 1
            match = D[i-1][j-1]
            mismatch = D[i-1][j-1] + 1
            if A[i-1] == B[j-1]:
                D[i][j] = min(insertion, deletion, match)
            else:
                D[i][j] = min(insertion, deletion, mismatch)
    
    
    return int(D[len(A)][len(B)])


if __name__ == "__main__":
    print(edit_distance(input(), input()))


# In[ ]:




