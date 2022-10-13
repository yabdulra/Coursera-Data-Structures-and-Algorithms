#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;
/*
In this problem, your goal is to simulate a sequence of merge operations with tables in a
database.
*/

struct DisjointSets {
	vector<int> row_counts;
	int max_table_size;
	vector <int> parents;
	vector<int> ranks;

	DisjointSets(vector<int> row_counts) : 
		row_counts(row_counts), max_table_size(*max_element(row_counts.begin(), row_counts.end())){
		for (int i = 0; i < row_counts.size(); i++) {
			parents.push_back(i);
			ranks.push_back(1);
		}
	}

	int getParent(int table) {
		// find parent and compress path
		vector<int> update_parents;

		while (table != parents[table]) {
			update_parents.push_back(parents[table]);
			table = parents[table];
		}

		for (auto elem : update_parents) parents[elem] = table;

		return table;
	}

	void merge(int destination, int source) {
		int realDestination = getParent(destination);
		int realSource = getParent(source);
		if (realDestination != realSource) {
			// merge two components
			// use union by rank heuristic
						// update max_table_size
			if (ranks[realSource] > ranks[realDestination]) {
				parents[realDestination] = realSource;
			}
			else {
				parents[realSource] = realDestination;
				if (ranks[realSource] == ranks[realDestination])
					ranks[realSource] += 1;
			}
			row_counts[realDestination] += row_counts[realSource];
			row_counts[realSource] = 0;

			if (max_table_size < row_counts[realDestination])
				max_table_size = row_counts[realDestination];
		}
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> counts(n);
	for (int i = 0; i != n; ++i) {
		cin >> counts[i];
	}

	DisjointSets tables(counts);

	for (int i = 0; i != m; ++i) {
		int destination, source;
		cin >> destination >> source;
		--destination;
		--source;

		tables.merge(destination, source);
		cout << tables.max_table_size << endl;
	}

	return 0;
}
