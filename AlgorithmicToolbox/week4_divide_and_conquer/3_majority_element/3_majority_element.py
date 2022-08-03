#!/usr/bin/env python
# coding: utf-8

# In[1]:


# Majority element
"""
Majority rule is a decision rule that selects the alternative which has a majority,
that is, more than half the votes.
Given a sequence of elements a1, a2, a3, . . ., an, you would like to check whether
it contains an element that appears more than n/2 times. 
"""

def majority_element_naive(elements):
    assert len(elements) <= 10 ** 5
    for e in elements:
        if elements.count(e) > len(elements) / 2:
            return 1

    return 0


def majority_element(elements):
    assert len(elements) <= 10 ** 5
    
    majority_elem = get_majority(elements, 0, len(elements)-1)
    
    count = 0
    for elem in elements:
        if elem == majority_elem:
            count += 1
    return 1 if count > (len(elements)//2) else 0


def get_majority(elements, low, high):
    
    if low == high:
        return elements[low]
    
    mid = low + (high-low)//2
    
    left_majority = get_majority(elements, low, mid)
    right_majority = get_majority(elements, mid+1, high)
    
    if left_majority == right_majority:
        return left_majority
    
    # otherwise, count each element and return the "winner".
    left_count = sum(1 for i in range(low, high+1) if elements[i] == left_majority)
    right_count = sum(1 for i in range(low, high+1) if elements[i] == right_majority)
    
    return left_majority if left_count > right_count else right_majority
    


if __name__ == '__main__':
    input_n = int(input())
    input_elements = list(map(int, input().split()))
    assert len(input_elements) == input_n
    print(majority_element(input_elements))


# In[ ]:




