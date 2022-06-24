#include <iostream>

/*
Solution to his ridiculously easy problem was provided by the
course instructor to show the pipeline of reading the problem 
statement, designing an algorithm, implementing it, testing and
debugging the solution, and submitting it to the grading system.
*/

int sum_of_two_digits(int first_digit, int second_digit) {
    return first_digit + second_digit;
}

int main() {
    int a = 0;
    int b = 0;
    std::cin >> a;
    std::cin >> b;
    std::cout << sum_of_two_digits(a, b);
    return 0;
}