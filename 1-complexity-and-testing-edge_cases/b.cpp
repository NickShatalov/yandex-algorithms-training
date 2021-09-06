#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

bool operator<(const Point& lhs, const Point& rhs) {
    if (lhs.x == rhs.x) {
        return lhs.y < rhs.y;
    }
    return lhs.x < rhs.x;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        vector<Point> points;
        for (int j = 0; j < 4; ++j) {
            int x, y;
            cin >> x >> y;
            points.push_back(Point{x, y});
        }
        sort(points.begin(), points.end());
        bool first_parallels =
            points[1].x - points[0].x == points[3].x - points[2].x &&
            points[1].y - points[0].y == points[3].y - points[2].y;
        bool second_parallels =
            points[2].x - points[0].x == points[3].x - points[1].x &&
            points[2].y - points[0].y == points[3].y - points[1].y;

        if (first_parallels && second_parallels) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
