#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# Maximum value of the loot
# python3
from sys import stdin

"""
*A thief finds much more loot than his bag can fit. Help him to find the most valuable combination
 of items assuming that any fraction of a loot item can be put into his bag.
*The goal of this code problem is to implement an algorithm for the fractional knapsack problem.
"""

def maximum_loot_value(capacity, weights, prices):
    assert 0 <= capacity <= 2 * 10 ** 6
    assert len(weights) == len(prices)
    assert 1 <= len(weights) <= 10 ** 3
    assert all(0 < w <= 2 * 10 ** 6 for w in weights)
    assert all(0 <= p <= 2 * 10 ** 6 for p in prices)
    
    A = [0]*len(weights)
    V = 0
    
    W = capacity
    for i in range(len(weights)):
        if W == 0:
            return V
        prices, weights = zip(*sorted(zip(prices, weights), key=lambda t: t[0]/t[1], reverse=True))
        
        prices = list(prices)
        weights = list(weights)
        
        a = min(weights[0], W)
        V += a*(prices[0]/weights[0])
        weights[0] -= a
        A[i] += a
        W -= a
        del prices[0]
        del weights[0]
    return V
        
        
if __name__ == "__main__":
    data = list(map(int, stdin.read().split()))
    n, input_capacity = data[0:2]
    input_prices = data[2:(2 * n + 2):2]
    input_weights = data[3:(2 * n + 2):2]
    opt_value = maximum_loot_value(input_capacity, input_weights, input_prices)
    print("{:.10f}".format(opt_value))

