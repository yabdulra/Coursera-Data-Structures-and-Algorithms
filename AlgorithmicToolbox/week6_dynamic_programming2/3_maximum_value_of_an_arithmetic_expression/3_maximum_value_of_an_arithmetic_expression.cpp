#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using std::vector;
using std::string;
using std::max;
using std::min;
/*
In this problem, your goal is to add parentheses to a given arithmetic
expression to maximize its value.
*/

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    }
    else if (op == '+') {
        return a + b;
    }
    else if (op == '-') {
        return a - b;
    }
    else {
        assert(0);
    }
}

void MinAndMax(int i, int j, vector<char> op, vector<vector<int> > m, vector<vector<int> > M, int& minimum, int& maximum) {
    for (int k = i; k != j; ++k) {
        int a = eval(M[i][k], M[k + 1][j], op[k]);
        int b = eval(M[i][k], m[k + 1][j], op[k]);
        int c = eval(m[i][k], M[k + 1][j], op[k]);
        int d = eval(m[i][k], m[k + 1][j], op[k]);

        vector<int> min_vec{ minimum, a, b, c, d };
        vector<int> max_vec{ maximum, a, b, c, d };
        minimum = *std::min_element(min_vec.begin(), min_vec.end());
        maximum = *std::max_element(max_vec.begin(), max_vec.end());

    }
}

long long get_maximum_value(const string& exp) {
    auto n = (exp.size() - 1) / 2;
    vector<vector<int> > m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int> > M(n + 1, vector<int>(n + 1, 0));

    vector<char> operators(n);
    vector<char> operands(n+1);

    for (auto i = 0; i != n; ++i) {
        operators[i] = exp[2 * i + 1];
    }

    for (auto j = 0; j != n + 1; ++j) {
        operands[j] = exp[2 * j];
        
    }

    for (auto k = 0; k != n + 1; ++k) {
        m[k][k] = operands[k] - '0';
        M[k][k] = operands[k] - '0';
    }

    for (auto i = 1; i != n + 1; ++i) {
        for (auto j = 0; j != n + 1 - i; ++j) {
            int k = i + j;
            int minimum = std::numeric_limits<int>::max();
            int maximum = std::numeric_limits<int>::min();
            MinAndMax(j, k, operators, m, M, minimum, maximum);
            m[j][k] = minimum;
            M[j][k] = maximum;
        }
    }


    return M[0][n];
}

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
}
