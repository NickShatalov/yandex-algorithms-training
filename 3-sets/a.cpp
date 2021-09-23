#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<bool> is_known(n, false);
    int known_num = 0;

    while (true) {
        string s;
        getline(cin, s);
        if (s == "") {
            continue;
        }
        if (s == "HELP") {
            break;
        }
        stringstream ss(s);
        vector<int> candidates;
        while (!ss.eof()) {
            int cur;
            ss >> cur;
            --cur;
            if (!is_known[cur]) {
                candidates.push_back(cur);
            }
        }

        if (2 * candidates.size() > n - known_num) {
            cout << "YES" << endl;
            known_num = n - candidates.size();
            for (int i = 0; i < n; ++i) {
                is_known[i] = true;
            }
            for (int candidate : candidates) {
                is_known[candidate] = false;
            }
        }
        else {
            cout << "NO" << endl;
            known_num += candidates.size();
            for (int candidate : candidates) {
                is_known[candidate] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!is_known[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}
