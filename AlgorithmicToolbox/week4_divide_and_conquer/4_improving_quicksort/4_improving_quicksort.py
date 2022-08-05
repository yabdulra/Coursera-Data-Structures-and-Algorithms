#!/usr/bin/env python
# coding: utf-8

# In[ ]:


"""
The goal in this problem is to redesign a given implementation of the randomized quick sort
algorithm so that it works fast even on sequences containing many equal elements.
"""
# This 3-way partitioning uses the Dutch National Flag problem algorithm.

from random import randint

def partition3(A, l, r):
    
    lt = l  
    i = l   
    gt = r  
    pivot = A[l]   
    while i <= gt:
        
        if A[i] < pivot:
            A[lt], A[i] = A[i], A[lt]
            lt += 1
            i += 1
        elif A[i] > pivot:
            A[i], A[gt] = A[gt], A[i]
            gt -= 1
        else:
            i += 1
            
    return lt, gt


def randomized_quick_sort(array, l, r):
    if l >= r:
        return array
    
    k = randint(l, r)
    array[l], array[k] = array[k], array[l]
    
    m1, m2 = partition3(array, l, r)
    
    randomized_quick_sort(array, l, m1-1)
    randomized_quick_sort(array, m2+1, r)


if __name__ == '__main__':
    input_n = int(input())
    elements = list(map(int, input().split()))
    assert len(elements) == input_n
    randomized_quick_sort(elements, 0, len(elements) - 1)
    print(*elements)


# In[ ]:




