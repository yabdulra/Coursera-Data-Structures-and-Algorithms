#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

/*
Looking closely at the fibonacci series, the sum of n Fibonacci numbers is one less
the (n+2)th fibonacci number. We know that to find the last digit of a number, we find
that number mod10. We can therefore tweak the previous solution of fibonacci number n
mod m by setting m=10. We find the (n+2)th fibonacci number mod10 then subtract 1, and
if fib(n+2) mod10 is zero we return 9.
*/

long long pisanoPeriod(long long m) {
    long long previous = 0, current = 1;
    for (int i = 0; i < m * m; ++i) {
        long long tmp = previous;
        previous = current;
        current = (tmp + current) % m;
        if (previous == 0 && current == 1) {
            return i + 1;
        }
    }
}

long long last_digit_of_nplus2th_fib_number(long long n, long long m=10) {

    n = (n+2) % pisanoPeriod(m);

    if (n <= 1) return n;

    long long previous = 0, current = 1;
    for (long long i = 0; i < n - 1; ++i) {
        long long tmp = previous;
        previous = current;
        current = (current + tmp) % m;
    }
    return current;
}

long long last_digit_of_the_sum_of_fib_numbers(long long n) {
    if (last_digit_of_nplus2th_fib_number(n) == 0) {
        return 9;
    }
    else {
        return last_digit_of_nplus2th_fib_number(n) - 1;
    }
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n) << std::endl;
    std::cout << last_digit_of_the_sum_of_fib_numbers(n) << std::endl;
}
