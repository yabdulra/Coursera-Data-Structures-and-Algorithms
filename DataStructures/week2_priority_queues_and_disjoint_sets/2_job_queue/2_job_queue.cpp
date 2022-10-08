#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/*
You have a program which is parallelized and uses n independent threads to process the given list
of m jobs. Threads take jobs in the order they are given in the input. If there is a free thread,
it immediately takes the next job from the list. If a thread has started processing a job, it doesn't
interrupt or stop until it finishes processing the job. If several threads try to take jobs from
the list simultaneously, the thread with smaller index takes the job. For each job you know exactly
how long will it take any thread to process this job, and this time is the same for all the threads.
You need to determine for each job which thread will process it and when will it start processing.
*/

using std::vector;
using std::cin;
using std::cout;
using std::pair;
using std::make_pair;

class Node {
public:
    int iD = 0, nft = 0;

    Node(){}
    Node(int id, int nft) 
        : iD(id), nft(nft)
    {
    }
    // use operator overloading to enable node comparism in the queue
    bool operator<(Node const& second) const {
        if (nft == second.nft) {
            return (iD < second.iD);
        }
        return nft < second.nft;
    }

    bool operator>(Node const& second) const {
        if (nft == second.nft) {
            return iD > second.iD;
        }
        return nft > second.nft;
    }
};


class JobQueue {
private:
    int num_workers_ = 0;
    vector<int> jobs_;
    vector< pair<int, int> > result;
    // use priority queue to store worker nodes in a min_heap
    // make heap based on next free time and then based on id if nft are the same.
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;

    void WriteResponse() const {
      
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i].first << " " << result[i].second << "\n";
        }        
    }

    void ReadData() {
        int m;
        cin >> num_workers_ >> m;
        jobs_.resize(m);
        for (int i = 0; i != m; ++i)
            cin >> jobs_[i];  
        // push nodes to the heap
        for (int i = 0; i != num_workers_; ++i) {
            pq.push(Node(i, 0));
        }
    }
    
    void AssignJobs() {
        
        for (auto job : jobs_) {
            Node next_worker = pq.top();  // get available node
            pq.pop(); // delete it from the queue
            // add the node to the array of nodes that picked a job
            result.push_back(make_pair(next_worker.iD, next_worker.nft));
            next_worker.nft += job;   // update nft of the node
            pq.push(next_worker);  // push it back to the queue
        }
    }   

public:
    void Solve() {
        ReadData();
        AssignJobs();
        WriteResponse();
    }
};


int main() {
    std::ios_base::sync_with_stdio(false);
    JobQueue job_queue;
    job_queue.Solve();

    return 0;
}
