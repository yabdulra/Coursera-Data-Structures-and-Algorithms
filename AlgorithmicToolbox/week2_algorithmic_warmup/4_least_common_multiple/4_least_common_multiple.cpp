#include <iostream>
#include <cstdlib>

/*
The least common multiple of two positive integers a and b is the least positive
integer m that is divisible by both a and b.
Given two integers a and b, find their least common multiple.

We have previously solved for greatest common divisor. Interestingly, least common 
multiple of two positive integers = abs(a*b)/gcd(a, b). Let's use this to solve this
problem.
*/
long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long)a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long)a * b;
}

long long int gcd_division_based(int a, int b) {
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }

    return (long long) a;
}

long long lcm(long long int a, long long int b) {
    return (long long) abs(a * b) / gcd_division_based(a, b);
}

int main() {
    int a, b;
    std::cin >> a >> b;
    //std::cout << lcm_naive(a, b) << std::endl;
    std::cout << lcm(a, b) << std::endl;
    return 0;
}