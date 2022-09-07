#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
/*
You are given a set of bars of gold and your goal is to take as much gold as possible into
your bag. There is just one copy of each bar and for each bar you can either take it or not
(hence you cannot take a fraction of a bar).
we solve this problem assuming that value of gold is the same as its weight
we therefore set w = v = weights
*/

int optimal_weight(int W, const vector<int>& w) {
    //write your code here
    vector<int> vec(W + 1);
    vector<vector<int> > D(w.size() + 1, vec);
    for (auto i = 0; i != w.size() + 1; ++i) D[i][0] = 0;
    for (auto j = 0; j != W + 1; ++j) D[0][j] = 0;

    for (auto i = 1; i != w.size() + 1; ++i) {
        for (auto j = 1; j != W + 1; ++j) {
            D[i][j] = D[i - 1][j];
            if (w[i - 1] <= j) {
                auto val = D[i - 1][j - w[i - 1]] + w[i - 1];
                if (D[i][j] < val) D[i][j] = val;
            }
        }
    }

    return D[w.size()][W];
}

int main() {
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w) << '\n';
}
