#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

typedef unsigned long long ull;

struct Rectangle {
    ull x1, y1, x2, y2;
};

struct Event {
    // state == 0 -- start of the rectangle
    // state == 1 -- end of the rectangle
    int state;
    size_t rect_idx;
    ull x;
};

bool operator<(const Event& lhs, const Event& rhs) {
    return lhs.x == rhs.x && lhs.state < rhs.state || lhs.x < rhs.x;
}

int main() {
    ull n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<Rectangle> rectangles(n);
    for (size_t i = 0; i < n; ++i) {
        ull x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rectangles[i] = {x1, y1, x2, y2};
    }

    vector<Event> events;
    events.reserve(n * 2);
    for (size_t i = 0; i < n; ++i) {
        auto& rect = rectangles[i];
        events.push_back({0, i, rect.x1});
        events.push_back({1, i, rect.x2});
    }
    sort(events.begin(), events.end());

    ull res = 0;
    set<size_t> rect_indices;
    rect_indices.insert(events[0].rect_idx);
    for (size_t i = 1; i < n * 2; ++i) {
        auto& event = events[i];

        vector<tuple<size_t, ull, int>> events_2;
        events_2.reserve(rect_indices.size() * 2);
        for (auto rect_idx : rect_indices) {
            events_2.push_back({rect_idx, rectangles[rect_idx].y1, +1});
            events_2.push_back({rect_idx, rectangles[rect_idx].y2, -1});
        }
        sort(events_2.begin(), events_2.end(),
             [](const auto& lhs, const auto& rhs) {
                 return get<1>(lhs) < get<1>(rhs);
             });
        ull h = 0;
        ull cnt = 1;
        for (size_t j = 1; j < rect_indices.size() * 2; ++j) {
            if (cnt > 0) {
                h += get<1>(events_2[j]) - get<1>(events_2[j - 1]);
            }
            cnt += get<2>(events_2[j]);
        }
        ull prev_x = events[i - 1].x;
        res += (event.x - prev_x) * h;

        if (event.state == 0) {
            rect_indices.insert(event.rect_idx);
        } else {  // envent.state == 1
            rect_indices.erase(event.rect_idx);
        }
    }

    cout << res << endl;

    return 0;
}
