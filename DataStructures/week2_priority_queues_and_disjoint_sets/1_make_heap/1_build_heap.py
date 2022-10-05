#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# # python3


# def build_heap(data):
#     """Build a heap from ``data`` inplace.

#     Returns a sequence of swaps performed by the algorithm.
#     """
#     # The following naive implementation just sorts the given sequence
#     # using selection sort algorithm and saves the resulting sequence
#     # of swaps. This turns the given array into a heap, but in the worst
#     # case gives a quadratic number of swaps.
#     #
#     # TODO: replace by a more efficient implementation
#     swaps = []
#     for i in range(len(data)):
#         for j in range(i + 1, len(data)):
#             if data[i] > data[j]:
#                 swaps.append((i, j))
#                 data[i], data[j] = data[j], data[i]
#     return swaps


# def main():
#     n = int(input())
#     data = list(map(int, input().split()))
#     assert len(data) == n

#     swaps = build_heap(data)

#     print(len(swaps))
#     for i, j in swaps:
#         print(i, j)


# if __name__ == "__main__":
#     main()


# In[ ]:



# python3
swaps = []


def left_child_index(i):
    return 2*i+1

def right_child_index(i):
    return 2*i+2

def shift_down(i, data):
    max_index = i
    
    l = left_child_index(i)
    if l <= len(data)-1 and data[l] < data[max_index]:
        max_index = l
    
    r = right_child_index(i)
    if r <= len(data)-1 and data[r] < data[max_index]:
        max_index = r
    
    if i != max_index:
        data[i], data[max_index] = data[max_index], data[i]
        s = (i, max_index)
        swaps.append(s)
        
        shift_down(max_index, data)


def build_heap(data):
    
    size = len(data)

    for i in reversed(range(size//2)):
        shift_down(i, data)


def main():
    n = int(input())
    data = list(map(int, input().split()))
    assert len(data) == n

    build_heap(data)

    print(len(swaps))
    for i, j in swaps:
        print(i, j)


if __name__ == "__main__":
    main()
