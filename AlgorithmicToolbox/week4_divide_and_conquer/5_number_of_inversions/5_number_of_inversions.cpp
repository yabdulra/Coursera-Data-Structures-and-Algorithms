#include <iostream>
#include <vector>

using std::vector;

/*
An inversion of a sequence a0, a1, . . . , an-1 is a pair of indices 0 <= i < j < n such
that ai > aj . The number of inversions of a sequence in some sense measures how
close the sequence is to being sorted. For example, a sorted (in non-descending order)
sequence contains no inversions at all, while in a sequence sorted in descending order
any two elements constitute an inversion (for a total of n(n-1)/2 inversions).
The goal in this problem is to count the number of inversions of a given sequence.
*/
long long merge(vector<int>& a, vector<int>& b, size_t left, size_t midpoint, size_t right) {
    long long count = 0;
    int k = left, i = left;
    int j = midpoint + 1;

    while (i <= midpoint && j <= right){
        if (a[i] <= a[j]) {
            b[k] = a[i];
            k += 1;
            i += 1;
        }
        else {
            b[k] = a[j];
            count += (midpoint - i + 1);
            k += 1;
            j += 1;
        }
    }
    while (i <= midpoint) {
        b[k] = a[i];
        k += 1;
        i += 1;
    }
    while (j <= right) {
        b[k] = a[j];
        k += 1;
        j += 1;
    }

    for (int i = left; i <= right; i++) a[i] = b[i];

    return count;
}

long long merge_sort(vector<int>& a, vector<int>& b, size_t left, size_t right) {
    int count = 0;

    if (right <= left) return count;

    auto midpoint = left + (right - left) / 2;
    count += merge_sort(a, b, left, midpoint);
    count += merge_sort(a, b, midpoint + 1, right);
    count += merge(a, b, left, midpoint, right);

    return count;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    vector<int> b(a.size());
    std::cout << merge_sort(a, b, 0, a.size()-1) << '\n';
}
