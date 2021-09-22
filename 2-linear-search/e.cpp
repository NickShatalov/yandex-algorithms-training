#include <cmath>
#include <iostream>

using namespace std;

int main() {
    long long int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long int x3, y3, r;
    cin >> x3 >> y3 >> r;
    unsigned long long int res = 0;

    for (long long int x = x1; x <= x2; ++x) {
        double tmp = pow(r, 2) - pow(x - x3, 2);
        if (tmp >= 0) {
            long long int c1 = ceil(y3 - sqrt(tmp));
            long long int c2 = floor(y3 + sqrt(tmp));
            c1 = max(c1, y1);
            c2 = min(c2, y2);
            res += max(0LL, c2 - c1 + 1);
        }
    }
    cout << res << endl;

    return 0;
}
