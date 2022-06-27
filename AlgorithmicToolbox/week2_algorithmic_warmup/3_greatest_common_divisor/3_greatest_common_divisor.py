#!/usr/bin/env python
# coding: utf-8

# In[ ]:


"""
The greatest common divisor GCD(𝑎, 𝑏) of two non-negative integers 𝑎 and 𝑏
(which are not both equal to 0) is the greatest integer 𝑑 that divides both 𝑎 and 𝑏.
Your goal in this problem is to implement the Euclidean algorithm for computing
the greatest common divisor.
Efficient algorithm for computing the greatest common divisor is an important
basic primitive of commonly used cryptographic algorithms like RSA.

Implemented below is the Euclidean algorithm with division, subtraction, and recursion
implementations
"""


def gcd_naive(a, b):
    assert 1 <= a <= 2 * 10 ** 9 and 1 <= b <= 2 * 10 ** 9

    for divisor in range(min(a, b), 0, -1):
        if a % divisor == 0 and b % divisor == 0:
            return divisor

    assert False

def gcd_division_based(a, b):
    while b != 0:
        t = b
        b = a%b
        a = t
    
    return a

def gcd_subtraction_based(a, b):
    while a != b:
        if a > b:
            a = a - b
        else:
            b = b - a
    
    return a

def gcd_recursion_based(a, b):
    if b == 0:
        return a
    else:
        return gcd_recursive_based(b, a%b)

def gcd(a, b):
    assert 0 <= a <= 2 * 10 ** 9 and 0 <= b <= 2 * 10 ** 9
    
    if a == b:
        return a
    if a == 0:
        return b
    if b == 0:
        return a
    if a%2 == 0:
        if b%2 == 0:
            return 2*gcd(a>>1, b>>1)
        else:
            return gcd(a>>1, b)
    elif b%2 == 0:
        return gcd(a, b>>1)
    elif a%2 != 0 and b%2 != 0:
        return gcd(max(a, b)-min(a,b), min(a, b))


if __name__ == '__main__':
    input_a, input_b = map(int, input().split())
    print(gcd(input_a, input_b))

