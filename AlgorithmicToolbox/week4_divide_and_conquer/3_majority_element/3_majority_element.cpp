#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

/*
Majority rule is a decision rule that selects the alternative which has a majority,
that is, more than half the votes.
Given a sequence of elements a1, a2, a3, . . ., an, you would like to check whether
it contains an element that appears more than n/2 times.
*/

int get_majority_element(vector<int>& a, int left, int right) {
    if (left == right) return a[left];
    
    int mid =(right + left) / 2;

    int left_majority = get_majority_element(a, left, mid);
    int right_majority = get_majority_element(a, mid + 1, right);

    if (left_majority == right_majority) return left_majority;

    int left_count = 0, right_count = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == left_majority) left_count += 1;
        if (a[i] == right_majority) right_count += 1;
    }

    return (left_count > right_count) ? left_majority : right_majority;
}

int majority_element(vector<int>& a) {
    int majority_elem = get_majority_element(a, 0, a.size()-1);
    int count = 0;

    for (auto elem : a) {
        if (elem == majority_elem) count += 1;
    }

    return (count > a.size() / 2) ? 1 : 0;
}


int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << majority_element(a) << '\n';

    return 0;
}
