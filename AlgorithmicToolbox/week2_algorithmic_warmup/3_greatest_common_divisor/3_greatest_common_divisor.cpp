#include <iostream>

int gcd_naive(int a, int b) {
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++) {
        if (a % d == 0 && b % d == 0) {
            if (d > current_gcd) {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}

int gcd_division_based(int a, int b) {
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }

    return a;
}

int gcd_subtraction_based(int a, int b) {
    while (a != b)
    {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }

    return a;
}

int gcd_recursion_based(int a, int b) {
    
    if (b == 0) {
        return a;
    }
    else {
        return gcd_recursion_based(b, a % b);
    }
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd_division_based(a, b) << std::endl;
    std::cout << gcd_subtraction_based(a, b) << std::endl;
    std::cout << gcd_recursion_based(a, b) << std::endl;
    return 0;
}
