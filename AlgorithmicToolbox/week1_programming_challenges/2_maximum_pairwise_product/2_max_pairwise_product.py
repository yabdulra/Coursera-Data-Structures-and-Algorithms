#!/usr/bin/env python
# coding: utf-8

# In[ ]:


"""
This program finds the maximum product of two distinct numbers in a sequence
of non-negative integers.
The naive solution solves the problem by going through all possible pairs of
the input elements and finds the pair of distinct elements with the largest
product. The time complexity of this solution is O(n^2) which is too slow for
inputs involving large number of elements. We therefore need a faster algorithm.
"""

def max_pairwise_product_naive(array):
    product = 0
    for i in range(len(array)):
        for j in range(i + 1, len(array)):
            product = max(product, array[i] * array[j])
    return product

"""
The faster algorithm scans the array twice to get the largest and second
largest elements. It suffices to multiply the two largest elements of the
array.
"""
def MaxPairwiseProductFast(a):
    index = 0
    for i in range(1, len(a)):
        if a[i] > a[index]:
            index = i
    a[index], a[-1] = a[-1], a[index]
    index = 0
    for i in range (1, len(a)-1):
        if a[i] > a[index]:
            index = i
    a[index], a[-2] = a[-2], a[index]
    
    return a[-2]*a[-1]


if __name__ == "__main__":
    n = int(input())
    arr = [int(x) for x in input().split()]
    assert n >= 2
    assert len(arr) == n
    print(MaxPairwiseProductFast(arr))


# In[ ]:




