#!/usr/bin/env python
# coding: utf-8

from collections import namedtuple
import heapq

"""
You have a program which is parallelized and uses n independent threads to process the given list
of m jobs. Threads take jobs in the order they are given in the input. If there is a free thread,
it immediately takes the next job from the list. If a thread has started processing a job, it doesn't
interrupt or stop until it finishes processing the job. If several threads try to take jobs from
the list simultaneously, the thread with smaller index takes the job. For each job you know exactly
how long will it take any thread to process this job, and this time is the same for all the threads.
You need to determine for each job which thread will process it and when will it start processing.
"""

AssignedJob = namedtuple("AssignedJob", ["worker", "started_at"])

class Node:

    def __init__(self, iD, nft=0):    #nft=next_free_time
        self.iD = iD
        self.nft = nft

    def __lt__(self, other):
        if self.nft == other.nft:
            return self.iD < other.iD
        return self.nft < other.nft

    def __gt__(self, other):
        if self.nft == other.nft:
            return self.iD > other.iD
        return self.nft > other.nft
    

def assign_jobs(threads, jobs):
    result = []
    nodes = threads
    
    for job in jobs:
        next_worker = heapq.heappop(nodes)
        result.append(AssignedJob(next_worker.iD, next_worker.nft))
        next_worker.nft += job
        heapq.heappush(nodes, next_worker)
        

    return result

def main():
    n_workers, n_jobs = map(int, input().split())
    jobs = list(map(int, input().split()))
    assert len(jobs) == n_jobs
    
    threads = [Node(i) for i in range(n_workers)]
    
    assigned_jobs = assign_jobs(threads, jobs)

    for job in assigned_jobs:
        print(job.worker, job.started_at)


if __name__ == "__main__":
    main()

