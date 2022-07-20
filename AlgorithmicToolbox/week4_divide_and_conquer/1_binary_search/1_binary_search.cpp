#include <iostream>
#include <cassert>
#include <vector>
/*
In this problem, the goal is to implement the binary search algorithm that allows
searching very efficiently (even huge) lists, provided that the list is sorted.
*/
using std::vector;

int linear_search(const vector<int>& a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}

int binary_search(const vector<int>& a, int left, int right, int x) {
    if (right > left) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] > x) {
            binary_search(a, left, mid - 1, x);
        }
        else {
            binary_search(a, mid + 1, right, x);
        }
    }
    else {
        return -1;
    }
}


int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cout << binary_search(a, 0, a.size()-1, b[i]) << ' ';
    }
}
