#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<char, int> m;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        ++m[c];
    }

    string res;
    char buf = 0;
    for (auto [c, cnt] : m) {
        for (int i = 0; i < cnt / 2; ++i) {
            res += c;
        }
        if (!buf && cnt % 2 == 1) {
            buf = c;
        }
    }
    string tmp = res;
    reverse(tmp.begin(), tmp.end());
    if (!buf) {
        res = res + tmp;
    } else {
        res = res + buf + tmp;
    }
    cout << res << endl;

    return 0;
}
