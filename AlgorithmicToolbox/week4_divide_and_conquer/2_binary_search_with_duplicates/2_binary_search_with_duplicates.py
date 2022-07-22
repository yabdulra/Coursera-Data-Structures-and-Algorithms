#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3
# Binary search with duplicates
"""
Find the first occurence of an integer in the given sorted sequence of
integers (possibly with duplicates).
"""

def linear_search(keys, query):
    for i in range(len(keys)):
        if keys[i] == query:
            return i

    return -1


def binary_search(keys, low, high, query):
    assert all(keys[i] <= keys[i + 1] for i in range(len(keys) - 1))
    assert 1 <= len(keys) <= 3 * 10 ** 4
 
    if keys[low] == query:
        return low
    if low >= high:
        return -1
    mid = low + (high - low) // 2
    
    if keys[mid] == query and keys[mid-1] != query:
        return mid
    elif keys[mid] < query:
        return binary_search(keys, mid + 1, high, query)
    else:
        return binary_search(keys, low, mid-1, query)
        

if __name__ == '__main__':
    n = int(input())
    input_keys = list(map(int, input().split()))
    k = int(input())
    input_queries = list(map(int, input().split()))

    for q in input_queries:
        print(binary_search(input_keys, 0, len(input_keys)-1, q), end=' ')


# In[ ]:




