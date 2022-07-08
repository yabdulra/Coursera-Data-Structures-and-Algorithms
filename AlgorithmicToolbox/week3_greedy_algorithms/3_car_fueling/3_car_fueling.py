#!/usr/bin/env python
# coding: utf-8

# In[ ]:


"""
You are going to travel to another city that is located 𝑑 miles away from your home city. Your
car can travel at most 𝑚 miles on a full tank and you start with a full tank. Along your way,
there are gas stations at distances stop1, stop2, . . . ,stop𝑛 from your home city. What is the
minimum number of refills needed?
"""

def compute_min_number_of_refills(d, m, stops):
    assert 1 <= d <= 10 ** 5
    assert 1 <= m <= 400
    assert 1 <= len(stops) <= 300
    assert 0 < stops[0] and all(stops[i] < stops[i + 1] for i in range(len(stops) - 1)) and stops[-1] < d
    
    refill = 0
    distance = 0
    fuel = m
    if stops[0] > m or d - stops[-1] > m:
        return -1
    if stops[0] <= fuel:
        distance = stops[0]
        fuel -= stops[0]

    for i in range(1, len(stops)):
        if stops[i] - stops[i-1] > m:
            return -1
        elif stops[i] - stops[i-1] <= fuel:
            distance = stops[i]
            fuel = fuel - (stops[i]-stops[i-1])
        else:
            refill += 1
            fuel = m
            fuel = fuel - (stops[i]-stops[i-1])
    if d - stops[-1] <= fuel:
        distance = d
    else:
        refill += 1
        distance = d
        fuel = fuel - (d - stops[-1])
    
    return refill
                

if __name__ == '__main__':
    input_d = int(input())
    input_m = int(input())
    input_n = int(input())
    input_stops = list(map(int, input().split()))
    assert len(input_stops) == input_n

    print(compute_min_number_of_refills(input_d, input_m, input_stops))

