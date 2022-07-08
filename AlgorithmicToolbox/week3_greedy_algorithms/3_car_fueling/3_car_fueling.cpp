#include <iostream>
#include <vector>

/*
You are going to travel to another city that is located d miles away from your home city. Your
car can travel at most m miles on a full tank and you start with a full tank. Along your way,
there are gas stations at distances stop1, stop2, . . . ,stopn from your home city. What is the
minimum number of refills needed?
*/

int compute_min_refills(int dist, int tank, std::vector<int>& stops) {
    int distance = 0;
    int refill = 0;
    int fuel = tank;
    int n = stops.size();

    // base case
    if (stops[0] > tank || dist - stops[n - 1] > tank) {
        return -1;
    }
    if (stops[0] <= fuel) {
        distance = stops[0];
        fuel -= stops[0];
    }
    for (int i = 1; i < n; ++i) {
        if (stops[i] - stops[i - 1] > tank) {
            return -1;
        }
        else if (stops[i] - stops[i - 1] < fuel) {
            distance = stops[i];
            fuel -= (stops[i] - stops[i - 1]);
        }
        else {
            refill += 1;
            fuel = tank;
            fuel -= (stops[i] - stops[i - 1]);
        }
    }

    if (dist - stops[n - 1] <= fuel) {
        distance = dist;
    }
    else {
        refill += 1;
    }
    return refill;
}


int main() {
    int d = 0;
    std::cin >> d;
    int m = 0;
    std::cin >> m;
    int n = 0;
    std::cin >> n;

    std::vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> stops.at(i);

    std::cout << compute_min_refills(d, m, stops) << std::endl;;

    return 0;
}
