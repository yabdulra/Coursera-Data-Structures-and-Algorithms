#include <iostream>
#include <vector>
#include <algorithm>

/*
This program finds the maximum product of two distinct numbers in a sequence
of non-negative integers.
The naive solution solves the problem by going through all possible pairs of
the input elements and finds the pair of distinct elements with the largest
product. The time complexity of this solution is O(n^2) which is too slow for
inputs involving large number of elements. We therefore need a faster algorithm.

*/

long long int MaxPairwiseProductNaive(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}
/*
The faster algorithm scans the array twice to get the largest and second
largest elements. It suffices to multiply the two largest elements of the
array.
*/
long long int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int index = 0;
    int index2 = 0;
    int n = numbers.size();

    for (int i = 1; i < n; ++i) {
        if (numbers[i] > numbers[index]) {
            index = i;
        }
    }
    if (index == 1) {
        index2 = 2;
    }
    else {
        index2 = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (numbers[i] != numbers[index] && numbers[i] > numbers[index2]) {
            index2 = i;
        }
    }

    return ((long long)(numbers[index])) * ((long long)(numbers[index2]));
}


int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << std::endl;
    return 0;
}
