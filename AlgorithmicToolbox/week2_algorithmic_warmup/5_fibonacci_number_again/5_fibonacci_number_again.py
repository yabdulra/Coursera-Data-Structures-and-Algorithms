#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3
"""
In this problem, your goal is to compute 𝐹𝑛 modulo 𝑚, where 𝑛 may be really huge: up to 1014.
For such values of 𝑛, an algorithm looping for 𝑛 iterations will not fit into one second for 
sure. Therefore we need to avoid such a loop.
"""

def fibonacci_number_again_naive(n, m):
    assert 0 <= n <= 10 ** 18 and 2 <= m <= 10 ** 3

    if n <= 1:
        return n

    previous, current = 0, 1
    for _ in range(n - 1):
        previous, current = current, (previous + current) % m

    return current


"""
From the example of F2015 mod 3, we can see that Fn mod m = F(n%pisano_period)%m
this will indeed greatly help to avoid unnecessary computation of large Fibonacci numbers.
Now Let's look for a way to find the Pisano period of any number m
"""
def pisanoPeriod(m):
    # Since a Fibonacci number is defined by its last two previous,
    # the case is the same for the mod series, this way we avoid
    # computing the Fibonacci number
    # The mod sequence always start with 0, 1
    previous, current = 0, 1
    for i in range(0, m * m):
        previous, current = current, (previous + current) % m
        # A Pisano Period starts with 01, we loop through the modes
        # until we get to 01 again and return the count.
        if previous == 0 and current == 1:
            return i + 1


def fibonacci_number_again(n, m):
    assert 0 <= n <= 10 ** 18 and 2 <= m <= 10 ** 3
    # Getting the period
    n = n % pisanoPeriod(m)

    # Deal with base case
    if n <= 1:
        return n
    previous, current = 0, 1
    for i in range(n-1):
        previous, current = current, (previous + current)%m

    return current


if __name__ == '__main__':
    input_n, input_m = map(int, input().split())
    print(fibonacci_number_again(input_n, input_m))


# In[ ]:




