#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3
import numpy as np
from math import inf
"""
In this problem, your goal is to add parentheses to a given arithmetic
expression to maximize its value.
"""

def compute(x, y, operator):
    if operator == '+':
        return x + y
    elif operator == '-':
        return x - y
    elif operator == '*':
        return x * y

def MinAndMax(i, j, operators, m, M):
    minimum = inf
    maximum = -inf
    
    for k in range(i, j):
        a = compute(M[i][k], M[k+1][j], operators[k])
        b = compute(int(M[i][k]), int(m[k+1][j]), operators[k])
        c = compute(int(m[i][k]), int(M[k+1][j]), operators[k])
        d = compute(int(m[i][k]), int(m[k+1][j]), operators[k])
        
        minimum = min(minimum, a, b, c, d)
        maximum = max(maximum, a, b, c, d)
    
    return minimum, maximum

def find_maximum_value(dataset):
    assert 1 <= len(dataset) <= 29

    n = (len(dataset)-1)//2
    m = np.zeros((n+1, n+1))
    M = np.zeros((n+1, n+1))
    
    operators = [None]*n
    for op in range(n):
        operators[op] = dataset[2*op + 1]
    
    operands = [None]*(n+1)
    for oprnd in range(n+1):
        operands[oprnd] = dataset[2*oprnd]
    
    for i in range(n+1):
        m[i][i] = operands[i]
        M[i][i] = operands[i]
    
    for s in range(1, n+1):
        for i in range(0, n+1-s):
            j = i + s
            m[i][j], M[i][j] = MinAndMax(i, j, operators, m, M)
    
    return int(M[0][n])



if __name__ == "__main__":
    print(find_maximum_value(input()))


# In[ ]:




