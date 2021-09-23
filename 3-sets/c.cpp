#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    deque<pair<int, int>> next_day;
    vector<int> periods(k);

    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        next_day.push_back({i, a});
        periods[i] = b;
    }

    sort(next_day.begin(), next_day.end(), [](pair<int, int>& lhs, pair<int, int> rhs) {
        return lhs.second < rhs.second;
    });

    int cur_day = next_day.front().second;
    int res = 0;
    while (cur_day < n) {
        if (cur_day % 7 < 5) {
            ++res;
        }
        while (next_day.front().second == cur_day) {
            auto& el = next_day.front();
            next_day.push_back({el.first, el.second + periods[el.first]});
            next_day.pop_front();
        }
        sort(next_day.begin(), next_day.end(), [](pair<int, int>& lhs, pair<int, int> rhs) {
            return lhs.second < rhs.second;
        });

        cur_day = next_day.front().second;
    }
    cout << res << endl;

    return 0;
}
