#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;
/*
You are given a description of a rooted tree. Your task is to compute and output its
height. Recall that the height of a (rooted) tree is the maximum depth of a node, or 
the maximum distance from a leaf to the root. You are given an arbitrary tree, not 
necessarily a binary tree.
*/

class Treeheight {
	private:
		int n = 0;
		vector<int> parents;
		vector<int> length;

	public:
		Treeheight() {}
		
		void set_nodes(const int num) {
			n = num;
		}

		void set_parents(const vector<int>& p) {
			for (auto node : p) {
				parents.push_back(node);
				length.push_back(0);
			}
		}

		int depth_from_node(int i) {
			int parent = parents[i];
			
			if (parent == -1) return 1;
			if (length[i]) return length[i];

			length[i] = 1 + this->depth_from_node(parents[i]);

			return length[i];
		}

		int compute_height() {
			int max_depth = 0;
			for (int i = 0; i != n; ++i) {
				max_depth = std::max(max_depth, this->depth_from_node(i) );
			}

			return max_depth;
		}
};


int main() {

	Treeheight tree_height;
	int n;
	std::cin >> n;

	vector<int> parents(n);
	for (int i = 0; i != n; ++i) {
		std::cin >> parents[i];
	}

	tree_height.set_nodes(n);
	tree_height.set_parents(parents);
	
	std::cout << tree_height.compute_height() << std::endl;

	return 0;
}