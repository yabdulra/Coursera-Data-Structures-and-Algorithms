#!/usr/bin/env python

# python3
"""
The goal is to implement efficient algorithm for computing Fibonacci numbers.
A naive recursive algorithm computes nth Fibonacci number by recursively calling
Fib(n-1)+Fib(n-2). This algorithm is too slow because Fib(40) already takes
noticeable time.
A faster way of computing this is to compute store already Fibs of 1 to n and
return Fib(n) = arr[-1].
"""

def fibonacci_number_naive(n):
    assert 0 <= n <= 45

    if n <= 1:
        return n

    return fibonacci_number_naive(n - 1) + fibonacci_number_naive(n - 2)


def fibonacci_number(n):
    assert 0 <= n <= 45

    if n <= 1:
        return n
    else:
        f_numbers = [1, 1]
        for i in range(2, n):
            f_numbers.append(f_numbers[-2]+f_numbers[-1])
        return f_numbers[-1]


if __name__ == '__main__':
    input_n = int(input())
    print(fibonacci_number(input_n))