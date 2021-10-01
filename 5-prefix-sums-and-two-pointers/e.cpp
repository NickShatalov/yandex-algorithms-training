#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef pair<char, char> pcc;
typedef pair<char, int> pci;
typedef pair<int, int> pii;
typedef unsigned long long ull;

int main() {
    string s;
    cin >> s;
    vector<pci> rle;
    vector<ull> v(256, 0);
    char cur = 0;
    ull cnt = 0;
    for (size_t i = 0; i <= s.size(); ++i) {
        char c = s[i];
        if (c != cur) {
            if (cnt) {
                v[cur] = max(v[cur], cnt);
                rle.push_back({cur, cnt});
            }
            cur = c;
            cnt = 0;
        }
        ++cnt;
    }

    map<pcc, vector<pii>> m;
    for (size_t i = 0; i < rle.size() - 1; ++i) {
        auto& [c1, n1] = rle[i];
        auto& [c2, n2] = rle[i + 1];
        m[{c1, c2}].push_back({n1, n2});
    }
    ull res = 0;
    for (auto& [chars, counts] : m) {
        sort(counts.begin(), counts.end(), [](const pii& lhs, const pii& rhs) {
            return lhs.first > rhs.first ||
                   (lhs.first == rhs.first && lhs.second > rhs.second);
        });
        ull cur_max = 0;
        ull tmp = 0;
        for (auto& [x, y] : counts) {
            if (y > cur_max) {
                tmp += x * (y - cur_max);
                cur_max = y;
            }
        }
        res += tmp;
    }
    for (auto cnt : v) {
        res += cnt;
    }
    cout << res << endl;

    return 0;
}
