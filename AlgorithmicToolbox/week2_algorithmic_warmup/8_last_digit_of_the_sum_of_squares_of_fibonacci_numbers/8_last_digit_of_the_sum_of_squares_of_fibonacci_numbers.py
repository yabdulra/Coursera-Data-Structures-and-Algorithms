#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# last digit of the sum of squares Fibonacci numbers

"""
To solve this problem, we use the property of sum of N Fibonacci numbers
Given fibonacci numbers F1, F2, ..., Fn, their sum of squares = F(n)*F(n+1)
To simplify our calculations, we use the fib(n mod m) function with m=10.
This function below calculates the mod 10 of a fibonacci number indexed at n plus some offset p.
p >= 0 for n <= 1 and p can be any integer otherwise
"""

def last_digit_of_the_sum_of_squares_of_fibonacci_numbers_naive(n):
    assert 0 <= n <= 10 ** 18

    if n <= 1:
        return n

    fibonacci_numbers = [0] * (n + 1)
    fibonacci_numbers[0] = 0
    fibonacci_numbers[1] = 1
    for i in range(2, n + 1):
        fibonacci_numbers[i] = fibonacci_numbers[i - 2] + fibonacci_numbers[i - 1]

    return sum([f ** 2 for f in fibonacci_numbers]) % 10

def pisanoPeriod(m):
    previous, current = 0, 1
    for i in range(0, m * m):
        previous, current = current, (previous + current) % m
        if previous == 0 and current == 1:
            return i + 1

def last_digit_of_nplus_pth_fibonacci_number(n, p, m=10):
    assert 0 <= n <= 10 ** 18 and 2 <= m <= 10 ** 3
    
    n = (n+p) % pisanoPeriod(m)

    if n <= 1:
        return n
    previous, current = 0, 1
    for i in range(n-1):
        previous, current = current, previous + current

    return current%m

def last_digit_of_the_sum_of_squares_of_fibonacci_numbers(n):
    assert 0 <= n <= 10 ** 18

    # We utilize the modular multiplication property (a*b)%c = (a%c * b%c)%c
    
    fn_mod_10 = last_digit_of_nplus_pth_fibonacci_number(n, 0)
    fn_plus1_mod_10 = last_digit_of_nplus_pth_fibonacci_number(n, 1)
    
    return (fn_mod_10 * fn_plus1_mod_10) % 10


if __name__ == '__main__':
    input_n = int(input())
    print(last_digit_of_the_sum_of_squares_of_fibonacci_numbers(input_n))


# In[ ]:




