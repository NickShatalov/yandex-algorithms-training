#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Event {
    // states:
    // 0 -- close
    // 1 -- open
    int state;
    ll x;
    size_t idx;
};

bool operator<(const Event& lhs, const Event& rhs) {
    return lhs.x == rhs.x && lhs.state < rhs.state || lhs.x < rhs.x;
}

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> pairs;
    pairs.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        pairs.push_back({a, b});
    }

    vector<Event> events;
    events.reserve(n * 2);
    for (size_t i = 0; i < n; ++i) {
        auto [a, b] = pairs[i];
        events.push_back({1, a, i});
        events.push_back({0, b, i});
    }
    sort(events.begin(), events.end());
    events.insert(events.begin(), {-1, 0, 0});

    ull res = 1LL << 42;
    pair<size_t, size_t> res_idx{0, 0};
    set<size_t> opened_set;
    for (size_t i = 0; i < n * 2; ++i) {
        auto& event = events[i];
        if (event.state == 1) {
            size_t idx = lower_bound(events.begin(), events.end(),
                                     Event{0, pairs[event.idx].second, 0}) -
                         events.begin() - 1;
            if (events[idx].state == 1) {
                ull tmp = pairs[event.idx].second - events[idx].x;
                if (tmp < res && events[idx].idx != event.idx) {
                    res = tmp;
                    res_idx = {event.idx, events[idx].idx};
                }
                if (tmp < res && !opened_set.empty()) {
                    res = tmp;
                    res_idx = {event.idx, *opened_set.begin()};
                }
            }
            opened_set.insert(event.idx);
        } else if (event.state == 0) {
            opened_set.erase(event.idx);
        }
    }

    if (res_idx == pair<size_t, size_t>{0, 0}) {
        cout << 0 << endl;
        return 0;
    }
    cout << res_idx.first + 1 << " " << res_idx.second + 1 << endl;

    return 0;
}
