#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main() {
    int m, n;
    cin >> m >> n;

    vector<pair<size_t, ull>> deers(m);
    vector<pair<size_t, ull>> elves(n);
    for (size_t i = 0; i < deers.size(); ++i) {
        ull tmp;
        cin >> tmp;
        deers[i] = {i, tmp};
    }
    for (size_t i = 0; i < elves.size(); ++i) {
        ull tmp;
        cin >> tmp;
        elves[i] = {i, tmp};
    }

    sort(deers.begin(), deers.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second < rhs.second;
    });
    sort(elves.begin(), elves.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second < rhs.second;
    });

    vector<int> first_elves(m, -1);
    vector<int> second_elves(m, -1);

    int cnt = 0;
    int deer_idx = 0, elf_idx = 0;
    int res = 0;
    while (cnt < n / 2 && deer_idx < deers.size() && elf_idx < elves.size()) {
        if (deers[deer_idx].second > elves[elf_idx].second) {
            first_elves[deers[deer_idx].first] = elves[elf_idx].first;
            ++deer_idx;
            ++elf_idx;
            ++cnt;
            continue;
        }
        ++deer_idx;
    }
    --deer_idx;
    elf_idx = elves.size() - 1;
    while (cnt > 0 && deer_idx >= 0 && elf_idx >= 0) {
        if (first_elves[deers[deer_idx].first] == -1) {
            --deer_idx;
            continue;
        }
        if (deers[deer_idx].second < elves[elf_idx].second) {
            second_elves[deers[deer_idx].first] = elves[elf_idx].first;
            ++res;
            --deer_idx;
            --elf_idx;
            --cnt;
            continue;
        }
        --deer_idx;
    }

    cout << res << endl;
    for (size_t i = 0; i < first_elves.size(); ++i) {
        if (first_elves[i] >= 0 && second_elves[i] >= 0) {
            cout << i + 1 << " " << first_elves[i] + 1 << " "
                 << second_elves[i] + 1 << endl;
        }
    }

    return 0;
}
