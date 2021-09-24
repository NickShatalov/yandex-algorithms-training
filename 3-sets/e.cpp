#include <array>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    const vector<long long int> p = {1'000'000'007, 1'000'000'009, 1'000'000'011};
    vector<unordered_set<long long int>> fibonacci_sets(p.size());
    vector<array<int, 2>> previous_numbers(p.size()); 
    for (int j = 0; j < p.size(); ++j) {
        fibonacci_sets[j].insert(1);
        previous_numbers[j] = {1, 1};
        for (int i = 0; i < 40000; ++i) {
            long long int q = (previous_numbers[j][0] + previous_numbers[j][1]) % p[j];
            fibonacci_sets[j].insert(q);
            previous_numbers[j][0] = previous_numbers[j][1];
            previous_numbers[j][1] = q;
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        bool flag = true;
        for (int j = 0; j < p.size(); ++j) {
            long long int res = 0;
            for (char c : s) {
                res = (res * 10 + c - '0') % p[j];
            }
            flag &= fibonacci_sets[j].contains(res);
        }
        if (flag) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
