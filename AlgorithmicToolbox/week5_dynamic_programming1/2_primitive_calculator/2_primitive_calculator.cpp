#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::vector;
/*
You are given a primitive calculator that can perform the following three operations
with the current number x: multiply x by 2, multiply x by 3, or add 1 to x. Your goal
is given a positive integer n, find the minimum number of operations needed to obtain
the number n starting from the number 1.
*/
vector<int> optimal_sequence_naive(int n) {
    std::vector<int> sequence;
    while (n >= 1) {
        sequence.push_back(n);
        if (n % 3 == 0) {
            n /= 3;
        }
        else if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n = n - 1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}


vector<int> optimal_sequence(int n) {
    vector<int> sequence{ n };   // vector to store the optimal sequence
    vector<int> min_operations(n + 1, 0); // initialize minimum operations to 0 for n numbers
    // start from index 2
    for (int i = 2; i != n + 1; ++i) {
        int case1 = INT_MAX, case2 = INT_MAX, case3 = INT_MAX, min_case;
        //compute number of operations at index i for three cases
        case1 = min_operations[i - 1] + 1;
        if (i % 2 == 0) case2 = min_operations[i / 2] + 1;
        if (i % 3 == 0) case3 = min_operations[i / 3] + 1;
        // find and select the minimum
        min_case = std::min({ case1, case2, case3 });
        min_operations[i] = min_case;
    }

    while (n > 1) {
        // extract the exact squence to arrive at n
        if (n % 3 == 0 && min_operations[n] - 1 == min_operations[n / 3]) {
            sequence.push_back(n / 3);
            n = n / 3;
        }
        else if (n % 2 == 0 && min_operations[n] - 1 == min_operations[n / 2]) {
            sequence.push_back(n / 2);
            n = n / 2;
        }
        else {
            sequence.push_back(n - 1);
            n = n - 1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}


int main() {
    int n;
    std::cin >> n;
    vector<int> sequence = optimal_sequence(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
}
