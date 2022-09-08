#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3

from itertools import product
from sys import stdin
import numpy as np
"""
You and two of your friends have just returned back home after visiting various countries.
Now you would like to evenly split all the souvenirs that all three of you bought.
"""

def partition3(values):
    assert 1 <= len(values) <= 20
    assert all(1 <= v <= 30 for v in values)
    
    # returns 1 if a given set can be partiotioned into 3 with equal sum else 0
    total_sum = sum(values)
    
    # this handles base cases, that is, if number of items in the set is less than 3 or
    # the total sum is not divisible by 3. zero is returned in these cases.
    if len(values) < 3 or total_sum%3 != 0:
        return 0
    
    # here W is the total sum of each of the three subsets
    W = total_sum//3
    count = 0 
    value = np.zeros((W+1, len(values)+1))
    for i in range(1, W+1):
        for j in range(1, len(values)+1):
            value[i][j] = value[i][j-1]
            if values[j-1]<=i:
                val = value[i-values[j-1]][j-1] + values[j-1]
                if val > value[i][j]:
                    value[i][j] = val
            if value[i][j] == W: count += 1
    
    return 0 if count < 3 else 1


if __name__ == '__main__':
    input_n, *input_values = list(map(int, stdin.read().split()))
    assert input_n == len(input_values)
    print(partition3(input_values))
#     input_n = int(input())
#     input_values = [int(i) for i in input().split()]
#     assert input_n == len(input_values)
#     print(partition3(input_values))

