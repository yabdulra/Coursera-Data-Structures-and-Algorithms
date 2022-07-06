#include <iostream>
#include <algorithm>
#include <vector>

/*
*A thief finds much more loot than his bag can fit. Help him to find the most valuable
 combination of items assuming that any fraction of a loot item can be put into his bag.
*The goal of this code problem is to implement an algorithm for the fractional knapsack
 problem.
*/

using namespace std;

struct Item
{
    int a, b;
    double c = static_cast<double>(a) / b;
};

bool sortbylast(const Item& a, const Item& b) {
    return (a.c > b.c);
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

    int size = weights.size();
    vector < Item > my_vec(size);
    vector <double> A(size, 0.0);


    for (int i = 0; i < size; ++i) {
        my_vec[i] = { values[i], weights[i]};
    }

    // sort according to value-weight ratio in reverse order.
    std::sort(my_vec.begin(), my_vec.end(), sortbylast);

    int W = capacity;
    for (int i = 0; i < weights.size(); ++i) {
        if (W == 0) return value;

        double a = min(my_vec[0].b, W);
        value += a * my_vec[0].c;
        my_vec[0].b -= a;

        W -= a;

        my_vec.erase(my_vec.begin());


    }

    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;


    return 0;
}