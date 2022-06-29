#include <iostream>
#include <vector>

/*
In this problem, your goal is to compute Fn modulo m, where n may be really huge: up to 1014.
For such values of n, an algorithm looping for n iterations will not fit into one second for
sure. Therefore we need to avoid such a loop.
*/

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return (long long) current % m;
}

/*
From the example of F2015 mod 3, we can see that Fn mod m = F(n%pisano_period)%m
this will indeed greatly help to avoid unnecessary computation of large Fibonacci numbers.
Now Let's look for a way to find the Pisano period of any number m
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

long long get_fibonacci_huge_mod_m(long long n, long long m) {
    
    n = n % pisanoPeriod(m);

    if (n <= 1) return n;

    long long previous = 0, current = 1;
    for (long long i = 0; i < n - 1; ++i) {
        long long tmp = previous;
        previous = current;
        current = (current + tmp)%m;
    }
    return current; 

    /*
    // A different  of doing this is by using a vector, but this adds additional
    // space complexity.

    std::vector <long long int> fib;
    long long int temp;
    fib.push_back(0);
    fib.push_back(1);
    for (int i = 1; i < n; ++i) {
        long long s = fib.size();
        temp = fib[s-1] + fib[s - 2];
        temp = temp % m;
        fib.push_back(temp);
    }
    return fib[fib.size()-1];
    */
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_mod_m(n, m) << '\n';
}
