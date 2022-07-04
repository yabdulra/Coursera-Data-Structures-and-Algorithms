#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# Money change
# python3

"""
This program implements an elementary greedy algorithm used by cashiers all over the world
millions of times per day.
The goal is to find the minimum number of coins needed to change the input value (an integer)
into coins with denominations 1, 5, and 10.

"""

def money_change(money):
    assert 0 <= money <= 10 ** 3
    
    coins_list = [0]*3
    
    if money == 0:
        return 0
    
    den1, den2, den3 = 10, 5, 1
    if money//den1 > 0:
        coins_list[0] = money//den1
        money = money%den1
    if money//den2 > 0:
        coins_list[1] = money//den2
        money = money%den2
    if money//den3 > 0:
        coins_list[2] = money
    return sum(coins_list)
    


if __name__ == '__main__':
    input_money = int(input())
    print(money_change(input_money))


# In[ ]:




