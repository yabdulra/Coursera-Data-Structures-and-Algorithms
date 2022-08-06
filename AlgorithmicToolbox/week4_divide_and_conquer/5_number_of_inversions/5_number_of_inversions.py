#!/usr/bin/env python
# coding: utf-8

# In[ ]:


"""
An inversion of a sequence a0, a1, . . . , an−1 is a pair of indices 0 ≤ i < j < n such
that ai > aj . The number of inversions of a sequence in some sense measures how
close the sequence is to being sorted. For example, a sorted (in non-descending
order) sequence contains no inversions at all, while in a sequence sorted in descending order
any two elements constitute an inversion (for a total of n(n − 1)/2 inversions).
The goal in this problem is to count the number of inversions of a given sequence.
"""

from itertools import combinations


def compute_inversions_naive(a):
    number_of_inversions = 0
    for i, j in combinations(range(len(a)), 2):
        if a[i] > a[j]:
            number_of_inversions += 1
    return number_of_inversions

def compute_inversions(a):    
    _arr = [0]*len(a)
    return merge_sort(a, _arr, 0, len(a)-1)

def merge_sort(a, _arr, low, high):
    count = 0
    
    if high <= low:
        return 0
    midpoint = low + (high - low)//2
    count += merge_sort(a, _arr, low, midpoint)
    count += merge_sort(a, _arr, midpoint+1, high)
    count += merge(a, _arr, low, midpoint, high)
    
    return count

def merge(a, _arr, low, midpoint, high):
    k = i = low
    j = midpoint + 1
    count = 0
    
    while i <= midpoint and j <= high:
        if a[i] <= a[j]:
            _arr[k] = a[i]
            k = k + 1
            i = i + 1
        else:
            _arr[k] = a[j]
            count += (midpoint - i + 1)
            k = k + 1
            j = j + 1
    while i <= midpoint:
        _arr[k] = a[i]
        k = k + 1
        i = i + 1   
    while j <= high:
        _arr[k] = a[j]
        k = k + 1
        j = j + 1
    for i in range(low, high + 1):
        a[i] = _arr[i]
 
    return count
    

if __name__ == '__main__':
    input_n = int(input())
    elements = list(map(int, input().split()))
    assert len(elements) == input_n
    print(compute_inversions(elements))


# In[ ]:




