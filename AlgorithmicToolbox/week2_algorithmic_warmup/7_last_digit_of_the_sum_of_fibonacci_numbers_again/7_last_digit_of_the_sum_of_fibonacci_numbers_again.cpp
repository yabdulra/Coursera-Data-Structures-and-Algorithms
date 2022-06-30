#include <iostream>
#include <vector>
using std::vector;

/*
To solve this problem, we use the property of sum of N Fibonacci numbers
Given fibonacci numbers F1, F2, ..., Fn, their sum = F(n+2) - F2
This holds for any given starting and end indexes, with the starting index being
F1 and the end index Fn.
To simplify our calculations, we use the fib(n mod m) function with m=10.
This function below calculates the mod 10 of a fibonacci number indexed at n plus 
some offset p. p >= 0 for n <= 1 and p can be any integer otherwise
*/

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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

long long get_fibonacci_partial_sum(long long from, long long to) {
    long long sum_fib_from_index = last_digit_of_nplus_pth_fib_number(from, 1);
    long long sum_fib_to_index = last_digit_of_nplus_pth_fib_number(to, 2);

    // recall (a-b)%c = (a%c-b%c)%c
    long long diff = sum_fib_to_index - sum_fib_from_index;

    return diff > 0 ? diff % 10 : (10 + diff) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << std::endl;
    std::cout << get_fibonacci_partial_sum(from, to) << std::endl;
}
