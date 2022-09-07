#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3

from sys import stdin
import numpy as np
"""
You are given a set of bars of gold and your goal is to take as much gold as possible into
your bag. There is just one copy of each bar and for each bar you can either take it or not
(hence you cannot take a fraction of a bar).
we solve this problem assuming that value of gold is the same as its weight
we therefore set w = v = weights
"""

def maximum_gold(capacity, weights):
    assert 1 <= capacity <= 10 ** 4
    assert 1 <= len(weights) <= 10 ** 3
    assert all(1 <= w <= 10 ** 5 for w in weights)
    
    W = capacity
    w = weights

    D = np.ones((len(w)+1, W+1))
    
    for i in range(len(w)+1):
        D[i][0] = 0
    for j in range(W+1):
        D[0][j] = 0
    
    for i in range(1, len(w)+1):
        for j in range(1, W+1):
            D[i][j] = D[i-1][j]
            if w[i-1] <= j:
                val = D[i-1][j-w[i-1]] + w[i-1]
                if D[i][j] < val:
                    D[i][j] = val
    
    return int(D[len(w)][W])


if __name__ == '__main__':
    input_capacity, n, *input_weights = list(map(int, stdin.read().split()))
    assert len(input_weights) == n

    print(maximum_gold(input_capacity, input_weights))

