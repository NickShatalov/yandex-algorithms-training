#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string res;
    vector<int> cnt1(10, 0);
    vector<int> cnt2(10, 0);
    for (auto c : s1) {
        ++cnt1[c - '0'];
    }
    for (auto c : s2) {
        ++cnt2[c - '0'];
    }
    for (int i = 9; i >= 0; --i) {
        for (int j = 0; j < min(cnt1[i], cnt2[i]); ++j) {
            res += '0' + i;
        }
    }
    if (res == "") {
        cout << -1 << endl;
    } else {
        if (res[0] == '0') {
            res = "0";
        }
        cout << res << endl;
    }

    return 0;
}
