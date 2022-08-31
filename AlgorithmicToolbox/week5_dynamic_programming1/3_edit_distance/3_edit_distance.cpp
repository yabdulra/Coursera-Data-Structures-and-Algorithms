#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
/*
The edit distance between two strings is the minimum number of operations (insertions, deletions,
and substitutions of symbols) to transform one string into another. It is a measure of similarity
of two strings. Edit distance has applications, for example, in computational biology, natural
language processing, and spell checking. Your goal in this problem is to compute the edit distance
between two strings.
*/
int edit_distance(const string& str1, const string& str2) {
	vector<int> d(str2.size()+1);
	vector<vector<int> > D(str1.size()+1, d);
	for (auto i = 0; i != str1.size() + 1; ++i) {
		D[i][0] = i;
	}
	for (auto j = 0; j != str2.size() + 1; ++j) {
		D[0][j] = j;
	}
	for (auto i = 1; i != str1.size() + 1; ++i) {
		for (auto j = 1; j != str2.size() + 1; ++j) {
			int insertion = D[i][j - 1] + 1;
			int deletion = D[i - 1][j] + 1;
			int match = D[i - 1][j - 1];
			int mismatch = D[i - 1][j - 1] + 1;

			if (str1[i - 1] == str2[j - 1]) {
				D[i][j] = std::min({ insertion, deletion, match });
			}
			else {
				D[i][j] = std::min({ insertion, deletion, mismatch });
			}
		}
	}
	return D[str1.size()][str2.size()];
}

int main() {
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	return 0;
}
