#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main() {
    string s;
    cin >> s;
    ull res = (s.length() + 2) / 2 * (s.length() + 1);

    vector<ull> v(s.length() + 1, 0);
    for (size_t i = 0; i < s.length(); ++i) {
        int shift = s[i] == '(' ? 1 : -1;
        v[i + 1] = v[i] + shift;
    }
    size_t prev_i = 0;
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i] == 0) {
            res += (i - prev_i) / 2 * (i - prev_i - 1);
            prev_i = i;
        }
    }

    cout << res << endl;

    return 0;
}
