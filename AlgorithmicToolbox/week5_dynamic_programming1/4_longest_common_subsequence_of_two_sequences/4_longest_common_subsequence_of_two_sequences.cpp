#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
/*
Compute the length of a longest common subsequence of two sequences.
Example: a common subsequence between [2 7 8 3] and [5 2 8 7] is (2, 7)
another one is (2, 8), so the program should return 2 i.e the number of
common subsequence.
*/
int lcs2(vector<int>& a, vector<int>& b) {
    
    vector<int> v(b.size() + 1);
    vector<vector<int> > D(a.size() + 1, v);
    for (auto i = 0; i != a.size() + 1; ++i) D[i][0] = 0;
    for (auto j = 0; j != b.size() + 1; ++j) D[0][j] = 0;

    for (auto i = 1; i != a.size() + 1; ++i) {
        for (auto j = 1; j != b.size() + 1; ++j) {
            if (a[i - 1] == b[j - 1]) {
                D[i][j] = 1 + D[i - 1][j - 1];
            }
            else {
                D[i][j] = std::max({ D[i][j - 1], D[i - 1][j] });
            }
        }
    }

    return D[a.size()][b.size()];
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    size_t m;
    std::cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::cout << lcs2(a, b) << std::endl;
}
