#include <iostream>

/*
To solve this problem, we use the property of sum of N Fibonacci numbers
Given fibonacci numbers F1, F2, ..., Fn, their sum of squares = F(n)*F(n+1)
To simplify our calculations, we use the fib(n mod m) function with m=10.
This function below calculates the mod 10 of a fibonacci number indexed at n plus
some offset p. p >= 0 for n <= 1 and p can be any integer otherwise
*/

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

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

long long last_digit_of_nplus_pth_fib_number(long long n, int p, long long m = 10) {

    n = (n + p) % pisanoPeriod(m);

    if (n <= 1) return n;

    long long previous = 0, current = 1;
    for (long long i = 0; i < n - 1; ++i) {
        long long tmp = previous;
        previous = current;
        current = (current + tmp) % m;
    }
    return current;
}

long long last_digit_of_the_sum_of_squares_of_fib_num(long long n) {

    long long fn_mod_10 = last_digit_of_nplus_pth_fib_number(n, 0);
    long long fn_plus1_mod_10 = last_digit_of_nplus_pth_fib_number(n, 1);

    // recall (a*b)%c = (a%c * b%c)%c

    return (fn_mod_10 * fn_plus1_mod_10) % 10;
}


int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_squares_naive(n) << std::endl;
    std::cout << last_digit_of_the_sum_of_squares_of_fib_num(n) << std::endl;
}
