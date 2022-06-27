#include <iostream>
/*
The goal is to find the last digit og nth-Fibonacci number. But Fibonacci
numbers grow exponentially fast, therefore Fib(n)%10 will turn out to be too slow
when n is sufficiently large.
Why not store the last digit of the ith Fibonacci number in Fib(i) instead of the 
number itself?

It is interesting to know that the series of the last digits of Fibonacci number
repeats itself after a cycle of length 60. With this, we can keep the range of our
loop to be n%60. This will further speed up the solution.
*/
int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit(int n) {
    if (n <= 1) return n;

    int previous = 0;
    int current = 1;

    for (int i = 0; i < ((n-1) % 60); ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }
    
    return current;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
}
