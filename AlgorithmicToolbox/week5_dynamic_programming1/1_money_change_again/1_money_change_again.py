#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3

"""
As we already know, a natural greedy strategy for the change problem does not work correctly for
any set of denominations. For example, if the available denominations are 1, 3, and 4, the greedy
algorithm will change 6 cents using three coins (4 + 1 + 1) while it can be changed using just
two coins (3 + 3). Your goal now is to apply dynamic programming for solving the Money Change
Problem for denominations 1, 3, and 4.

"""
def change_naive(money):
    min_coins = float("inf")

    for num1 in range(money + 1):
        for num3 in range(money // 3 + 1):
            for num4 in range(money // 4 + 1):
                if 1 * num1 + 3 * num3 + 4 * num4 == money:
                    min_coins = min(min_coins, num1 + num3 + num4)

    return min_coins


def change(money):
    assert 0 <= money <= 10 ** 3
    
    MinNumCoins = [0]*(money+1)
    coins = [1, 3, 4]
    
    for m in range(1, money+1):
        MinNumCoins[m] = float('inf')
        for i in range(len(coins)):
            if m >= coins[i]:
                NumCoins = MinNumCoins[m-coins[i]] + 1
                if NumCoins < MinNumCoins[m]:
                    MinNumCoins[m] = NumCoins
    
    
    return MinNumCoins[money]
    

if __name__ == '__main__':
    amount = int(input())
    print(change(amount))


# In[ ]:




