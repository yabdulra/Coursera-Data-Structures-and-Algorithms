#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

/*
The goal in this problem is to redesign a given implementation of the randomized quick sort
algorithm so that it works fast even on sequences containing many equal elements.
*/

void partition3(vector<int>& a, int l, int r, int &p1, int &p2) {
    int x = a[l], i = l;
    p1 = l;
    p2 = r;
    
    while (i <= p2) {
        if (a[i] < x) {
            swap(a[i], a[p1]);
            p1++;
            i++;
        }
        else if (a[i] > x) {
            swap(a[i], a[p2]);
            p2--;
        }
        else {
            i++;
        }
    }
}

void randomized_quick_sort(vector<int>& a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int m1, m2;
    partition3(a, l, r, m1, m2);

    randomized_quick_sort(a, l, m1 - 1);
    randomized_quick_sort(a, m2 + 1, r);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}
