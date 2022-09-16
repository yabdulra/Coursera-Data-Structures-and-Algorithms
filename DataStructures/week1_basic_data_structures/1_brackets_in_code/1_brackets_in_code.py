#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3

"""
In this problem you will implement a feature for a text editor to find errors in the usage 
of brackets in the code.
"""

from collections import namedtuple

Bracket = namedtuple("Bracket", ["char", "position"])


def are_matching(left, right):
    return (left + right) in ["()", "[]", "{}"]


def find_mismatch(text):
    opening_brackets_stack = []
    history = []
    for i, next in enumerate(text, start=1):
        if next in "([{":
            # Process opening bracket, write your code here
            opening_brackets_stack.append(Bracket(next, i))

        if next in ")]}":
            # Process closing bracket, write your code here
            if not opening_brackets_stack:
                return i
            
            top = opening_brackets_stack.pop().char
            if not are_matching(top, next):
                return i
        
    if opening_brackets_stack:
        top = opening_brackets_stack.pop()
        return top[1]
    
    return "Success"

def main():
    text = input()
    mismatch = find_mismatch(text)
    # Printing answer, write your code here
    print(mismatch)


if __name__ == "__main__":
    main()

