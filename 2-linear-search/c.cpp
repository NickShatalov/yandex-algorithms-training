#include <iostream>

using namespace std;

int main() {
    int a[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            a[i][j] = 0;
        }
    }

    int n;
    cin >> n;
    for (int k = 0; k < n; ++k) {
        int i, j;
        cin >> i >> j;
        a[i][j] = 4;
        if (a[i - 1][j] > 0) {
            --a[i][j];
            --a[i - 1][j];
        }
        if (a[i + 1][j] > 0) {
            --a[i][j];
            --a[i + 1][j];
        }
        if (a[i][j - 1] > 0) {
            --a[i][j];
            --a[i][j - 1];
        }
        if (a[i][j + 1] > 0) {
            --a[i][j];
            --a[i][j + 1];
        }
    }

    int res = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            res += a[i][j];
        }
    }
    cout << res << endl;

    return 0;
}