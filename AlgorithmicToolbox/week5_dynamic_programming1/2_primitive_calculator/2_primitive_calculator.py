#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3

"""
You are given a primitive calculator that can perform the following three operations with
the current number x: multiply x by 2, multiply x by 3, or add 1 to x. Your goal is given a
positive integer n, find the minimum number of operations needed to obtain the number n
starting from the number 1.
"""

def greedyCalculator(n):
    operations = 0
    while n > 1:
        operations += 1
        if n%3 == 0:
            n = n/3
        elif n%2 == 0:
            n = n/2
        else:
            n -= 1
    
    return operations

def compute_operations(n):
    assert 1 <= n <= 10 ** 6
    
    MinNumOperations = [0]*(n+1)
    outputSequence = [n]
    # numbers = [1, 2, 3]  : numbers that can be used to add or multiply
    for i in range(2, n+1):
        case1, case2, case3 = float('inf'), float('inf'), float('inf')
        case1 = MinNumOperations[i-1] + 1
        if i%2 == 0: case2 = MinNumOperations[i//2] + 1 
        if i%3 == 0: case3 = MinNumOperations[i//3] + 1 
        min_case = min(case1, case2, case3)
        MinNumOperations[i] = min_case
    
    while n > 1:
        if n%3 == 0 and MinNumOperations[n]-1 == MinNumOperations[n//3]:
            outputSequence = [n//3] + outputSequence
            n = n//3
        elif n%2 == 0 and MinNumOperations[n]-1 == MinNumOperations[n//2]:
            outputSequence = [n//2] + outputSequence
            n = n//2
        else:
            outputSequence = [n-1] + outputSequence
            n = n-1
        
        
    return outputSequence


if __name__ == '__main__':
    input_n = int(input())
    output_sequence = compute_operations(input_n)
    print(len(output_sequence) - 1)
    print(*output_sequence)


# In[ ]:




