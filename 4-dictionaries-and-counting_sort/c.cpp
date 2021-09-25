#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> counts(256, 0);
    for (char c : s) {
        ++counts[c];
    }
    vector<string> pairs(k);
    for (int i = 0; i < k; ++i) {
        cin >> pairs[i];
    }

    long long int res = 0;
    for (char c : s) {
        --counts[c];
        for (string& pair : pairs) {
            if (pair[0] == c) {
                res += counts[pair[1]];
            }
        }
    }
    cout << res << endl;

    return 0;
}
