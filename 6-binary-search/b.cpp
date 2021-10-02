#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main() {
    ull a, b, c, x, k;
    cin >> a >> b >> c >> x >> k;
    double coef = 1 + c / 100.0;
    if (x == 0) {
        cout << 0 << endl;
        return 0;
    }

    ull res = x / k;
    if (res >= a && res <= b) {
        res = a - 1;
    }

    ull l = a;
    ull r = b;
    while (l != r) {
        ull tmp = (l + r) / 2 + 1;
        if (tmp * k  * coef > x) {
            r = tmp - 1;
        } else {
            l = tmp;
        }
    }

    if (l > res && l * k * coef <= x) {
        res = l;
    }
    cout << res << endl;

    return 0;
}
