#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3
"""
As the last question of a successful interview, your boss gives you a few pieces of paper
with numbers on it and asks you to compose a largest number from these numbers. The
resulting number is going to be your salary, so you are very much interested in maximizing
this number. How can you do this?
"""
from itertools import permutations


def largest_number_naive(numbers):
    numbers = list(map(str, numbers))

    largest = 0

    for permutation in permutations(numbers):
        largest = max(largest, int("".join(permutation)))

    return largest


def largest_number(numbers):
    numbers = list(map(str, numbers))
    print(numbers)
    salary = []
    while len(numbers) > 0:
        max_digit = 0
        for number in numbers:
            if int(str(number)+str(max_digit))>=int(str(max_digit)+str(number)):
                max_digit = number
        salary.append(max_digit)
        numbers.remove(max_digit)
    return int("".join(salary))

if __name__ == '__main__':
    n = int(input())
    input_numbers = input().split()
    assert len(input_numbers) == n
    print(largest_number(input_numbers))

