#include <iostream>

/*
This program implements an elementary greedy algorithm used by cashiers all over the
world millions of times per day.
The goal is to find the minimum number of coins needed to change the input value 
(an integer) into coins with denominations 1, 5, and 10.
*/

int get_change(int m) {
	//write your code here
	int arr[3]{ 0 };
	int den1{ 10 }, den2{ 5 }, den3{ 1 }, sum{ 0 };

	if (m == 0) return 0;

	if ((m / den1) > 0) {
		arr[0] = m / den1;
		m = m % den1;
	}
	if ((m / den2) > 0) {
		arr[1] = m / den2;
		m = m % den2;
	}
	if ((m / den3) > 0) {
		arr[2] = m / den3;
	}
	for (int i = 0; i < 3; ++i) {
		sum = sum + arr[i];
	}

	return sum;
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << std::endl;
}
