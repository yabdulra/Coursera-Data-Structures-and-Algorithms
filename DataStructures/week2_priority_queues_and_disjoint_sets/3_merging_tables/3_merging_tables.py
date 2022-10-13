#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# python3
"""
In this problem, your goal is to simulate a sequence of merge operations with tables in a
database.
"""

class Database:
    def __init__(self, row_counts):
        self.row_counts = row_counts
        self.max = max(self.row_counts)
        n_tables = len(row_counts)
        self.ranks = [1] * (n_tables)
        self.parents = list(range(0, n_tables))

    def merge(self, src, dst):
        src_parent = self.get_parent(src)
        dst_parent = self.get_parent(dst)

        if src_parent == dst_parent:
            return

        # merge two components
        # use union by rank heuristic
        # update max_row_count with the new maximum table size
        if self.ranks[src_parent] > self.ranks[dst_parent]:
            self.parents[dst_parent] = src_parent
        else:
            self.parents[src_parent] = dst_parent
            if self.ranks[src_parent] == self.ranks[dst_parent]:
                self.ranks[src_parent] += 1

        self.row_counts[dst_parent] += self.row_counts[src_parent]
        self.row_counts[src_parent] = 0

        if self.max < self.row_counts[dst_parent]:
            self.max = self.row_counts[dst_parent]
        return True

    def get_parent(self, table):
        # here, table is the index where the table belongs
        update_parents = []
        
#         root = table
        while table != self.parents[table]:
            update_parents.append(self.parents[table])
            table = self.parents[table]
        
        for i in update_parents:
            self.parents[i] = table
            
        return table


def main():
    n_tables, n_queries = map(int, input().split())
    counts = list(map(int, input().split()))
    assert len(counts) == n_tables
    db = Database(counts)
    for i in range(n_queries):
        dst, src = map(int, input().split())
        db.merge(dst - 1, src - 1)
        print(db.max)


if __name__ == "__main__":
    main()
