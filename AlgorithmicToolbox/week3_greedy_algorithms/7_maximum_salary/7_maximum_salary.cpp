#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

/*
As the last question of a successful interview, your boss gives you a few pieces of 
paper with numbers on it and asks you to compose a largest number from these numbers.
The resulting number is going to be your salary, so you are very much interested in
maximizing this number. How can you do this?
*/

std::vector<std::string> largest_number(std::vector<std::string> a) {
    std::vector<std::string> salary;
    while (a.size() > 0) {
        std::string max_digit{'0'};
        int index{0};
        for (int i = 0; i < a.size(); ++i) {
            if (std::stoi(a[i] + max_digit) >= std::stoi(max_digit + a[i])) {
                max_digit = a[i];
                index = i;
            }
            
        }
        salary.push_back(max_digit);
        a.erase(a.begin() + index);
    }

    return salary;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }

    std::vector<std::string> salary = largest_number(a);
    for (auto x : salary) {
        std::cout << x;
    }

    return 0;
}
