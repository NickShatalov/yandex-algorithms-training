#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> counts(256, 0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            ++counts[c];
        }
    }
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            --counts[c];
        }
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        for (int i = 0; i < counts[c]; ++i) {
            cout << c;
        }
    }
    cout << endl;

    return 0;
}
