#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3
"""
In this problem, the goal is to implement the binary search algorithm that allows searching
very efficiently (even huge) lists, provided that the list is sorted.
"""

def linear_search(keys, query):
    for i in range(len(keys)):
        if keys[i] == query:
            return i

    return -1


def binary_search(keys, low, high, query):

    if high >= low:
 
        mid = (high + low) // 2
 
        if keys[mid] == query:
            return mid
        elif keys[mid] > query:
            return binary_search(keys, low, mid - 1, query)
        else:
            return binary_search(keys, mid + 1, high, query)
 
    else:
        return -1

if __name__ == '__main__':
    n = int(input())
    input_keys = list(map(int, input().split()))
    k = int(input())
    input_queries = list(map(int, input().split()))

    for q in input_queries:
        print(binary_search(input_keys, 0, len(input_keys)-1, q), end=' ')


# In[ ]:




