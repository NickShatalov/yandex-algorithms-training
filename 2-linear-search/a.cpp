#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int64_t res =
        *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
    cout << res << endl;

    return 0;
}
