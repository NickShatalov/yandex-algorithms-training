#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t k;
    cin >> k;
    vector<pair<long long, long long>> v(k + 4);
    for (size_t i = 0; i < k; ++i) {
        long long a, n;
        cin >> a >> n;
        v[i + 2] = {a, n};
    }
    for (size_t i : vector<size_t>{0, 1, v.size() - 1, v.size() - 2}) {
        v[i] = {0, 0};
    }

    vector<size_t> p = {2, v.size() - 3};
    size_t& p1 = p[0];
    size_t& p2 = p[1];
    while (true) {
        if (p1 == p2 && v[p1].second == 1) {
            cout << 1 << endl;
            cout << v[p1].first << endl;
            break;
        }
        if (p1 == p2 && v[p1].second == 2 ||
            p1 == p2 - 1 && v[p1].second == 1 && v[p2].second == 1) {
            cout << 2 << endl;
            cout << v[p1].first << " " << v[p2].first << endl;
            break;
        }

        for (int dir = 0; dir < p.size(); ++dir) {
            int shift = dir == 0 ? 1 : -1;
            size_t& cur_p = p[dir];
            int cnt = 0;
            for (size_t i : {cur_p, cur_p + shift}) {
                if (v[i].second == 1) {
                    ++cnt;
                } else {
                    break;
                }
            }
            if (cnt == 0) {
                long long val = v[cur_p].first;
                if (v[cur_p].second > 2) {
                    v[cur_p].second -= 2;
                    v[cur_p - shift] = {val, 1};
                    v[cur_p - 2 * shift] = {val, 1};
                    cur_p -= 2 * shift;
                } else if (v[cur_p].second == 2) {
                    --v[cur_p].second;
                    v[cur_p - shift] = {val, 1};
                    cur_p -= shift;
                }
            } else if (cnt == 1) {
                v[cur_p - shift] = v[cur_p];
                long long val = v[cur_p + shift].first;
                --v[cur_p + shift].second;
                v[cur_p] = {val, 1};
                cur_p -= shift;
            }
        }

        long long tmp = min(v[p1].first, v[p2].first);
        v[p1].first -= tmp;
        v[p1 + 1].first += tmp;
        v[p2].first -= tmp;
        v[p2 - 1].first += tmp;
        if (v[p1].first == 0) {
            ++p1;
        }
        if (v[p2].first == 0) {
            --p2;
        }
    }

    return 0;
}
