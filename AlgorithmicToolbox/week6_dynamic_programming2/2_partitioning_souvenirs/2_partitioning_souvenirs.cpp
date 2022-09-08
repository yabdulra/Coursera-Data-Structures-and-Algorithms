#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;
/*
You and two of your friends have just returned back home after visiting various countries.
Now you would like to evenly split all the souvenirs that all three of you bought.
*/
int partition3(vector<int>& A) {
    //write your code here
    int total_sum = std::accumulate(A.begin(), A.end(), 0);

    if (A.size() < 3 || total_sum % 3 != 0) return 0;

    int W = total_sum / 3;
    int count = 0;
    vector<vector<int> > value(W + 1, vector<int>(A.size() + 1));
    
    for (auto i = 1; i != W + 1; ++i) {
        for (auto j = 1; j != A.size() + 1; ++j) {
            value[i][j] = value[i][j - 1];
            if (A[j - 1] <= i) {
                int val = value[i - A[j - 1]][j - 1] + A[j - 1];
                if (val > value[i][j]) value[i][j] = val;
            }
            if (value[i][j] == W) count += 1;
        }
    }
    int rt;
    (count < 3) ? rt = 0 : rt = 1;

    return rt;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i) {
        std::cin >> A[i];
    }
    std::cout << partition3(A) << '\n';
}
