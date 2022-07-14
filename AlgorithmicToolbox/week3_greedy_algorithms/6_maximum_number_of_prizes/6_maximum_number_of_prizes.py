#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3
"""
You are organizing a funny competition for children. As a prize fund you have n
candies. You would like to use these candies for top k places in a competition
with a natural restriction that a higher place gets a larger number of candies.
To make as many children happy as possible, you are going to find the largest
value of k for which it is possible.
"""

def compute_optimal_summands(n):
    assert 1 <= n <= 10 ** 9
    summands = []
    if n <= 2:
        summands.append(n)

    reminder = n
    number = 0
    while sum(summands) < n:
        reminder -= number
        number += 1
        if reminder - number > number:
            summands.append(number)
        else:
            summands.append(reminder)

    return summands


if __name__ == '__main__':
    input_n = int(input())
    output_summands = compute_optimal_summands(input_n)
    print(len(output_summands))
    print(*output_summands)


# In[ ]:





# In[ ]:




