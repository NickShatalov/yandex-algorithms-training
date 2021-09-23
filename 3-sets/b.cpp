#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, set<int>> edges;

    int new_edges_num = 0;
    for (int k = 0; k < m; ++k) {
        int i, j;
        cin >> i >> j;
        --i;
        --j;
        if (i == j) {
            continue;
        }
        if (i > j) {
            swap(i, j);
        }
        if (!edges[i].contains(j)) {
            edges[i].insert(j);
            ++new_edges_num;
        }
    }

    cout << n << " " << new_edges_num << endl;
    for (auto& [i, s] : edges) {
        for (auto j : s) {
            cout << i + 1 << " " << j + 1 << endl;
        }
    }

    return 0;
}
