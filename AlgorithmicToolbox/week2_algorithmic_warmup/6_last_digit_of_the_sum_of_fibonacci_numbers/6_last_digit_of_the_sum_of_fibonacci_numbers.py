#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# last digit of the sum of FIbonacci numbers

def last_digit_of_the_sum_of_fibonacci_numbers_naive(n):
    assert 0 <= n <= 10 ** 18

    if n <= 1:
        return n

    fibonacci_numbers = [0] * (n + 1)
    fibonacci_numbers[0] = 0
    fibonacci_numbers[1] = 1
    for i in range(2, n + 1):
        fibonacci_numbers[i] = fibonacci_numbers[i - 2] + fibonacci_numbers[i - 1]

    return sum(fibonacci_numbers) % 10
"""
Looking closely at the fibonacci series, the sum of n Fibonacci numbers is one less the (n+2)th
fibonacci number. We know that to find the last digit of a number, we find that number mod10.
We can therefore tweak the previous solution of fibonacci number n mod m by setting m=10.
We find the (n+2)th fibonacci number mod10 then subtract 1, and if fib(n+2) mod10 is zero we
return 9.

"""

def pisanoPeriod(m):
    previous, current = 0, 1
    for i in range(0, m * m):
        previous, current = current, (previous + current) % m
        if previous == 0 and current == 1:
            return i + 1

def last_digit_of_nplus2th_fibonacci_number(n, m=10):
    assert 0 <= n <= 10 ** 18 and 2 <= m <= 10 ** 3
    
    n = (n+2) % pisanoPeriod(m)

    if n <= 1:
        return n
    previous, current = 0, 1
    for i in range(n-1):
        previous, current = current, previous + current

    return current%m
    
def last_digit_of_the_sum_of_fibonacci_numbers(n):
    assert 0 <= n <= 10 ** 18
    
    if last_digit_of_nplus2th_fibonacci_number(n) == 0:
        return 9
    else:
        return last_digit_of_nplus2th_fibonacci_number(n) - 1


if __name__ == '__main__':
    input_n = int(input())
    print(last_digit_of_the_sum_of_fibonacci_numbers(input_n))


# In[ ]:




