#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max;

/*

*/

void max_sliding_window_naive(vector<int> const& A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}


class StackWithMax {
    vector<int> stack;
    vector<int> aux_stack;

public:

    void Push(int value) {
        if (aux_stack.size() > 0) {
            if (value > aux_stack.back()) {
                aux_stack.push_back(value);
            }
            else {
                aux_stack.push_back(aux_stack.back());
            }
        }
        else {
            aux_stack.push_back(value);
        }

        stack.push_back(value);
    }

    int Pop() {
        assert(stack.size());
        int back = stack.back();
        stack.pop_back();
        aux_stack.pop_back();

        return back;
    }

    bool isEmpty() {
        return ((stack.size() == 0) ? true : false);
    }

    int Max()  {
        //assert(stack.size());
        if (isEmpty()) return NULL;
        else return aux_stack.back();
    }
};

class Queue {
private:
    StackWithMax inbox;
    StackWithMax outbox;

public:
    void Enqueue(int value) {
        inbox.Push(value);
    }

    void Dequeue() {
        if (outbox.isEmpty()) {
            while (!inbox.isEmpty()) {
                int item = inbox.Pop();
                outbox.Push(item);
            }
        }
        outbox.Pop();
    }

    int Max() {
        int inmax = inbox.Max(), outmax = outbox.Max();
        if (inmax != NULL && outmax != NULL) return max(inmax, outmax);
        else if (inmax != NULL) return inmax;
        else if (outmax != NULL) return outmax;
    }
};

void max_sliding_window(vector<int> const& A, int w) {
    Queue queue;
    vector<int> maximums;
    for (int i = 0; i != w; ++i) {
        queue.Enqueue(A[i]);
    }
    maximums.push_back(queue.Max());

    for (int i = w; i != A.size(); ++i) {
        queue.Dequeue();
        queue.Enqueue(A[i]);
        maximums.push_back(queue.Max());
    }

    for (auto elem : maximums) {
        cout << elem << " ";
    }

    return;
}




int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

    return 0;
}
