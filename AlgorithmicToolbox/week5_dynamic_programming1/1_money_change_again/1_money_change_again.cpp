#include <iostream>
#include <vector>
#include <limits>

/*
As we already know, a natural greedy strategy for the change problem does not work correctly for
any set of denominations. For example, if the available denominations are 1, 3, and 4, the greedy
algorithm will change 6 cents using three coins (4 + 1 + 1) while it can be changed using just
two coins (3 + 3). Your goal now is to apply dynamic programming for solving the Money Change
Problem for denominations 1, 3, and 4.
*/
int get_change(int m) {
	std::vector<int> MinNumCoins(m + 1, 0);
	int NumCoins, coins[3]{1, 3, 4};

	for (int i = 1; i < m+1; i++) {
		MinNumCoins[i] = std::numeric_limits<int>::max();
		
		for (int j = 0; j < sizeof(coins)/sizeof(coins[0]); j++) {
			if (i >= coins[j]) {
				NumCoins = MinNumCoins[i - coins[j]] + 1;
				if (NumCoins < MinNumCoins[i]) {
					MinNumCoins[i] = NumCoins;
				}
			}
		}
	}

	return MinNumCoins[m-1];
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
