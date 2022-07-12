#include <algorithm>
#include <iostream>
#include <vector>

/*
You have n ads to place on a popular Internet page. For each ad, you know how
much is the advertiser willing to pay for one click on this ad. You have set up n
slots on your page and estimated the expected number of clicks per day for each
slot. Now, your goal is to distribute the ads among the slots to maximize the
total revenue.
*/

long long max_dot_product(std::vector<int> a, std::vector<int> b) {
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long result = 0;
    for (size_t i = 0; i < a.size(); i++) {
        result += ((long long)a[i]) * b[i];
    }
    return result;
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (size_t i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::cout << max_dot_product(a, b) << std::endl;
}
