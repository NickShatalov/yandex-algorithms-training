#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    int imax = max_element(l.begin(), l.end()) - l.begin();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (i == imax) {
            continue;
        }
        sum += l[i];
    }

    int res;
    if (l[imax] > sum) {
        res = l[imax] - sum;
    } else {
        res = l[imax] + sum;
    }
    cout << res << endl;

    return 0;
}
