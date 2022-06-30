#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# last digit of the sum of Fibonacci numbers again
"""
To solve this problem, we use the property of sum of N Fibonacci numbers
Given fibonacci numbers F1, F2, ..., Fn, their sum = F(n+2) - F2
This holds for any given starting and end indexes, with the starting index being 
F1 and the end index Fn.
To simplify our calculations, we use the fib(n mod m) function with m=10.
This function below calculates the mod 10 of a fibonacci number indexed at n plus some offset p
p >= 0 for n <= 1 and p can be any integer otherwise
"""

def last_digit_of_the_sum_of_fibonacci_numbers_again_naive(from_index, to_index):
    assert 0 <= from_index <= to_index <= 10 ** 18

    if to_index == 0:
        return 0

    fibonacci_numbers = [0] * (to_index + 1)
    fibonacci_numbers[0] = 0
    fibonacci_numbers[1] = 1
    for i in range(2, to_index + 1):
        fibonacci_numbers[i] = fibonacci_numbers[i - 2] + fibonacci_numbers[i - 1]

    return sum(fibonacci_numbers[from_index:to_index + 1]) % 10

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

def last_digit_of_the_sum_of_fibonacci_numbers_again(from_index, to_index):
    assert 0 <= from_index <= to_index <= 10 ** 18
    
    # We utilize the modular subtraction property (a-b)%c = (a%c - b%c)%c
    # Here, sum_fib_from_index and sum_fib_to_index are all in mod 10
    sum_fib_from_index = last_digit_of_nplus_pth_fibonacci_number(from_index, 1)
    sum_fib_to_index = last_digit_of_nplus_pth_fibonacci_number(to_index, 2)
    
    return (sum_fib_to_index - sum_fib_from_index) % 10


if __name__ == '__main__':
    input_from, input_to = map(int, input().split())
    print(last_digit_of_the_sum_of_fibonacci_numbers_again(input_from, input_to)) 


# In[ ]:




