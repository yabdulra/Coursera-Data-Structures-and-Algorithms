#!/usr/bin/env python
# coding: utf-8

# In[30]:


# python3
"""
*You are responsible for collecting signatures from all tenants of a certain building. For each
*tenant, you know a period of time when he or she is at home.
*You would like to collect all signatures by visiting the building as few times as possible.
*The mathematical model for this problem is the following. You are given a set of segments on a
*line and your goal is to mark as few points on a line as possible so that each segment contains
*at least one marked point.

Hint: Sort segments according to their end times, make end time of the first segment the first
point. Loop through all and add their end times to points if they're disjoint with the current point.
"""
from collections import namedtuple
from operator import attrgetter
from sys import stdin

Segment = namedtuple('Segment', 'start end')


def compute_optimal_points(segments):
    
    
    points = []
    segments = sorted(segments, key=attrgetter('end'))
    point = segments[0].end
    points.append(point)
    for segment in segments:
        if point < segment.start or point > segment.end:
            point = segment.end
            points.append(point)
        
    
    return points

if __name__ == '__main__':
    n, *data = map(int, stdin.read().split())
    input_segments = list(map(lambda x: Segment(x[0], x[1]), zip(data[::2], data[1::2])))
    assert n == len(input_segments)
    output_points = compute_optimal_points(input_segments)
    print(len(output_points))
    print(*output_points)


# In[ ]:




