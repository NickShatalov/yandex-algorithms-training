// solved with 6th attempt
// hint: https://youtu.be/J65GNFfL94c

#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    n -= 2;

    vector<int> persons(n);
    for (int i = 0; i < n; ++i) {
        persons[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        swap(persons[a], persons[b]);
    }

    vector<bool> processed(n, false);
    deque<int> cycle;
    bool last_two_are_changed = false;
    for (int i = 0; i < n; ++i) {
        if (persons[i] == i) {
            continue;
        }
        if (processed[i]) {
            continue;
        }

        int cur_person = i;
        do {
            cycle.push_back(cur_person);
            processed[cur_person] = true;
            cur_person = persons[cur_person];
        } while (cur_person != i);

        cout << cycle[cycle.size() - 1] + 1 << " " << n + 1 << endl;
        while (cycle.size() > 2) {
            cout << cycle[0] + 1 << " " << n + 1 << endl;
            cycle.pop_front();
        }
        cout << cycle[0] + 1 << " " << n + 2 << endl;
        cout << cycle[0] + 1 << " " << n + 1 << endl;
        cout << cycle[1] + 1 << " " << n + 2 << endl;
        cycle.clear();
        last_two_are_changed = !last_two_are_changed;
    }
    if (last_two_are_changed) {
        cout << n + 1 << " " << n + 2 << endl;
    }

    return 0;
}
