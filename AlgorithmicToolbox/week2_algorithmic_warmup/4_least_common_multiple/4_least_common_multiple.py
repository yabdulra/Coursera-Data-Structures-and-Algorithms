#!/usr/bin/env python
# coding: utf-8

# In[ ]:


"""
The least common multiple of two positive integers 𝑎 and 𝑏 is the least positive
integer 𝑚 that is divisible by both 𝑎 and 𝑏.
Given two integers 𝑎 and 𝑏, find their least common multiple.

We have previously solved for greatest common divisor. Interestingly, least common multiple
of two positive integers = abs(a*b)/gcd(a, b). Let's use this to solve this problem.
"""

def lcm_naive(a, b):
    assert 1 <= a <= 2 * 10 ** 9 and 1 <= b <= 2 * 10 ** 9

    multiple = max(a, b)
    while multiple % a != 0 or multiple % b != 0:
        multiple += 1

    return multiple

def gcd(a, b):
    assert 0 <= a <= 2 * 10 ** 9 and 0 <= b <= 2 * 10 ** 9

    if a == b:
        return a
    if a == 0:
        return b
    if b == 0:
        return a
    if a % 2 == 0:
        if b % 2 == 0:
            return 2*gcd(a >> 1, b >> 1)
        else:
            return gcd(a >> 1, b)
    elif b % 2 == 0:
        print("I'm here")
        return gcd(a, b >> 1)
    elif a % 2 != 0 and b % 2 != 0:
        return gcd(max(a, b)-min(a, b), min(a, b))

def lcm(a, b):
    assert 1 <= a <= 2 * 10 ** 9 and 1 <= b <= 2 * 10 ** 9

    return abs(a*b)//gcd(a, b)
    


if __name__ == '__main__':
    input_a, input_b = map(int, input().split())
    print(lcm(input_a, input_b))


# In[ ]:




