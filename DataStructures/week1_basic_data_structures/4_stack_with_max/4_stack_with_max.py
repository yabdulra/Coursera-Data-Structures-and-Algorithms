#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#python3
import sys

"""
Stack is an abstract data type supporting the operations Push() and Pop(). It is not difficult
to implement it in a way that both these operations work in constant time. In this problem, you
goal will be to implement a stack that also supports finding the maximum value and to ensure
that all operations still work in constant time.

Soln: use an auxiliary stack and push back the greater element between the value and the back
of the stack. Always push the given value to the main stack and pop both stacks when pop() is 
called.
"""

class StackWithMax():
    def __init__(self):
        self.my_stack = []
        self.aux_stack = []

    def Push(self, a):
        if len(self.aux_stack) > 0:
            if a > self.aux_stack[-1]:
                self.aux_stack.append(a)
            else:
                self.aux_stack.append(self.aux_stack[-1])
        else:
            self.aux_stack.append(a)
        
        self.my_stack.append(a)

    def Pop(self):
        assert(len(self.my_stack))
        self.my_stack.pop()
        self.aux_stack.pop()

    def Max(self):
        assert(len(self.my_stack))
        
        return self.aux_stack[-1]


if __name__ == '__main__':
    stack = StackWithMax()

    num_queries = int(sys.stdin.readline())
    for _ in range(num_queries):
        query = sys.stdin.readline().split()

        if query[0] == "push":
            stack.Push(int(query[1]))
        elif query[0] == "pop":
            stack.Pop()
        elif query[0] == "max":
            print(stack.Max())
        else:
            assert(0)

