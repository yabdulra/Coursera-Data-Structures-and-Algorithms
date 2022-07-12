#!/usr/bin/env python
# coding: utf-8

# In[41]:


# python3

from itertools import permutations

"""
You have n ads to place on a popular Internet page. For each ad, you know how
much is the advertiser willing to pay for one click on this ad. You have set up n
slots on your page and estimated the expected number of clicks per day for each
slot. Now, your goal is to distribute the ads among the slots to maximize the
total revenue.

"""

def max_dot_product_naive(first_sequence, second_sequence):
    assert len(first_sequence) == len(second_sequence)
    assert len(first_sequence) <= 10 ** 3
    assert all(0 <= f <= 10 ** 5 for f in first_sequence)
    assert all(0 <= s <= 10 ** 5 for s in second_sequence)

    max_product = 0
    for permutation in permutations(second_sequence):
        dot_product = sum(first_sequence[i] * permutation[i] for i in range(len(first_sequence)))
        
        max_product = max(max_product, dot_product)

    return max_product


def max_dot_product(first_sequence, second_sequence):
    assert len(first_sequence) == len(second_sequence)
    assert len(first_sequence) <= 10 ** 3
    assert all(0 <= f <= 10 ** 5 for f in first_sequence)
    assert all(0 <= s <= 10 ** 5 for s in second_sequence)
    
    first_sequence.sort()
    second_sequence.sort()
    max_product = sum(first_sequence*second_sequence for first_sequence, second_sequence in zip(first_sequence, second_sequence))
    return max_product

if __name__ == '__main__':
    n = int(input())
    prices = list(map(int, input().split()))
    clicks = list(map(int, input().split()))
    assert len(prices) == len(clicks) == n
    print(max_dot_product(prices, clicks))


# In[ ]:




