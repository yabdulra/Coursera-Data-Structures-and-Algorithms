#include <iostream>
#include <vector>
#include <numeric>
/*
You are organizing a funny competition for children. As a prize fund you have n
candies. You would like to use these candies for top k places in a competition
with a natural restriction that a higher place gets a larger number of candies.
To make as many children happy as possible, you are going to find the largest
value of k for which it is possible.
*/
std::vector<int> optimal_summands(int n) {
    std::vector<int> summands;

    if (n <= 2) {
        summands.push_back(n);
    }

    int reminder = n, number = 0;

    while (std::accumulate(summands.begin(), summands.end(), 0) < n) {
        reminder -= number;
        number += 1;
        if (reminder - number > number) {
            summands.push_back(number);
        }
        else {
            summands.push_back(reminder);
        }
    }

    return summands;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << std::endl;
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
