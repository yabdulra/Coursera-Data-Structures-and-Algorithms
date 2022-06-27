#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3
"""
The goal is to find the last digit og nth-Fibonacci number. But Fibonacci
numbers grow exponentially fast, therefore Fib(n)%10 will turn out to be too slow
when n is sufficiently large.
Why not store the last digit of the ith Fibonacci number in Fib(i) instead of the 
number itself?

It is interesting to know that the series of the last digits of Fibonacci number
repeats itself after a cycle of length 60. With this, we can keep the range of our
loop to be n%60. This will further speed up the solution.
"""

def last_digit_of_fibonacci_number_naive(n):
    assert 0 <= n <= 10 ** 7

    if n <= 1:
        return n

    return (last_digit_of_fibonacci_number_naive(n - 1) + last_digit_of_fibonacci_number_naive(n - 2)) % 10


def last_digit_of_fibonacci_number(n):
    assert 0 <= n <= 10 ** 7
    a, b = 0, 1
    for i in range((n-1) % 60):
        a, b = b, (a + b) % 10
    return b

  
if __name__ == '__main__':
    input_n = int(input())
    print(last_digit_of_fibonacci_number(input_n))

