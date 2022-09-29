#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

/*
Stack is an abstract data type supporting the operations Push() and Pop(). It is not difficult
to implement it in a way that both these operations work in constant time. In this problem, you
goal will be to implement a stack that also supports finding the maximum value and to ensure
that all operations still work in constant time.

Soln: use an auxiliary stack and push back the greater element between the value and the back
of the stack. Always push the given value to the main stack and pop both stacks when pop() is
called.
*/

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

    void Pop() {
        assert(stack.size());
        stack.pop_back();
        aux_stack.pop_back();
    }

    int Max() const {
        assert(stack.size());
        // return *max_element(stack.begin(), stack.end());
        return aux_stack.back();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}