#include <iostream>
#include <vector>
#include <cassert>

/*
The goal is to implement efficient algorithm for computing Fibonacci numbers.
A naive recursive algorithm computes nth Fibonacci number by recursively calling
Fib(n-1)+Fib(n-2). This algorithm is too slow because Fib(40) already takes
noticeable time.
A faster way of computing this is to compute store already Fibs of 1 to n and
return Fib(n) = arr[-1].
*/
int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    std::vector<int> f_numbers;
    f_numbers.push_back(1);
    f_numbers.push_back(1);
    if (n <= 1) {
        return n;
    }
    else {
        for (int i = 2; i < n; ++i) {
            f_numbers.push_back(f_numbers[i - 2] + f_numbers[i - 1]);
        }

    }
    return f_numbers[n- 1];
}


void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;

    //std::cout << fibonacci_naive(n) << '\n';
    //test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}