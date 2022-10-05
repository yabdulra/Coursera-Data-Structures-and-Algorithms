#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
private:
    vector<int> data_;
    vector< pair<int, int> > swaps_;

    void WriteResponse() const {
        cout << swaps_.size() << "\n";
        for (int i = 0; i < swaps_.size(); ++i) {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }

    void ReadData() {
        int n;
        cin >> n;
        data_.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> data_[i];
    }

    int left_child_index(int i) { return 2 * i + 1; }
    int right_child_index(int i) { return 2 * i + 2; }

    void GenerateSwaps(int i) {
        //swaps_.clear();
        // The following naive implementation just sorts 
        // the given sequence using selection sort algorithm
        // and saves the resulting sequence of swaps.
        // This turns the given array into a heap, 
        // but in the worst case gives a quadratic number of swaps.
        //
        // TODO: replace by a more efficient implementation
        // solved
        int max_index = i;
        
        int l = left_child_index(i);
        if (l <= data_.size() - 1 && data_[l] < data_[max_index]) {
            max_index = l;
        }

        int r = right_child_index(i);
        if (r <= data_.size() - 1 && data_[r] < data_[max_index]) {
            max_index = r;
        }

        if (i != max_index) {
            swap(data_[i], data_[max_index]);
            swaps_.push_back(make_pair(i, max_index));
            GenerateSwaps(max_index);
        }
    }

    void BuildHeap() {
        auto size = data_.size();

        for (decltype(size) i = size / 2 - 1; i != -1; --i) {
            GenerateSwaps(i);
        }
    }

public:
    void Solve() {
        ReadData();
        //GenerateSwaps();
        BuildHeap();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
