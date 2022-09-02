#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
/*
Compute the length of a longest common subsequence of three sequences.
This extends the previous problem of two subsequences.
*/
int lcs3(vector<int>& a, vector<int>& b, vector<int>& c) {
    
    vector<int> d_1(c.size() + 1);
    vector<vector<int> > d_2(b.size() + 1, d_1);
    vector<vector<vector<int> > > D(a.size() + 1, d_2);

    for (auto i = 0; i != a.size() + 1; ++i) {
        for (auto j = 0; j != b.size() + 1; ++j) {
            D[i][j][0] = 0;
        }
    }
    for (auto j = 0; j != b.size() + 1; ++j) {
        for (auto k = 0; k != c.size() + 1; ++k) {
            D[0][j][k] = 0;
        }
    }
    for (auto k = 0; k != c.size() + 1; ++k) {
        for (auto i = 0; i != a.size() + 1; ++i) {
            D[i][0][k] = 0;
        }
    }

    for (auto i = 1; i != a.size() + 1; ++i) {
        for (auto j = 1; j != b.size() + 1; ++j) {
            for (auto k = 1; k != c.size() + 1; ++k) {
                if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1]) {
                    D[i][j][k] = 1 + D[i - 1][j - 1][k - 1];
                }
                else {
                    D[i][j][k] = std::max({D[i-1][j][k], D[i][j-1][k], D[i][j][k-1]});
                }
            }
        }
    }

    return D[a.size()][b.size()][c.size()];
}

int main() {
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++) {
        std::cin >> a[i];
    }
    size_t bn;
    std::cin >> bn;
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++) {
        std::cin >> b[i];
    }
    size_t cn;
    std::cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++) {
        std::cin >> c[i];
    }
    std::cout << lcs3(a, b, c) << std::endl;
}
