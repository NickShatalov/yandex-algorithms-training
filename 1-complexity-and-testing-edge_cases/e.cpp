#include <iostream>

using namespace std;

int main() {
    uint64_t p;
    cin >> p;

    if (p <= 2 || p == 4) {
        cout << -1 << endl;
        return 0;
    }

    // max
    uint64_t a_max, b_max, c_max;
    if (p % 3 == 0) {
        a_max = p / 3;
        b_max = a_max;
        c_max = a_max;
    } else if (p % 3 == 1) {
        a_max = p / 3;
        b_max = a_max;
        c_max = a_max + 1;
    } else if (p % 3 == 2) {
        c_max = p / 3;
        a_max = c_max + 1;
        b_max = c_max + 1;
    }

    // min
    uint64_t a_min, b_min, c_min;
    if (p == 3) {
        a_min = 1;
        b_min = 1;
        c_min = 1;
    } else {
        c_min = p % 2 ? 1 : 2;
        a_min = (p - c_min) / 2;
        b_min = a_min;
    }

    cout << a_max << " " << b_max << " " << c_max << endl;
    cout << a_min << " " << b_min << " " << c_min << endl;

    return 0;
}
