#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3

import sys, threading

"""
You are given a description of a rooted tree. Your task is to compute and output its height. Recall
that the height of a (rooted) tree is the maximum depth of a node, or the maximum distance from a
leaf to the root. You are given an arbitrary tree, not necessarily a binary tree.
"""

sys.setrecursionlimit(10**7) # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size

class TreeHeight:
#     lets create a constructor for this class
    def __init__(self):
        self.n = 0   # initializer forthe number of nodes
        self.parent = []  # initializer for thr parents list
        self.length = []  # list to store the path length from a given node in the tree
        
    def read(self):
        self.n = int(sys.stdin.readline())
        self.parent = list(map(int, sys.stdin.readline().split()))
        self.length = [0]*self.n   # since we have n nodes

    def depth_from_node_i(self, i):
        # parent nodes
        parent = self.parent[i]
        # Base case: the length is 1 at the root node whose parent is -1
        if parent == -1:
            return 1
        
        if self.length[i]:
            return self.length[i]
        
        self.length[i] = 1 + self.depth_from_node_i(self.parent[i])  # this calculates the depth
        # from node[1], which is just 1+ depth from its parent
        return self.length[i]
        
    def compute_height(self):
        # Replace this code with a faster implementation
        max_depth = 0  # we iterate here to update the maximum depth of the tree
        for i in range(self.n):
            max_depth = max(max_depth, self.depth_from_node_i(i))
        
        return max_depth

def main():
    tree = TreeHeight()
    tree.read()
    print(tree.compute_height())

threading.Thread(target=main).start()


# In[ ]:




