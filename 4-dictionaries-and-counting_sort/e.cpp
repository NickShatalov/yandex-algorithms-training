#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string res;

    vector<unsigned int> cnt1(256, 0);
    vector<deque<unsigned int>> pos1(256);
    for (unsigned int i = 0; i < s1.size(); ++i) {
        ++cnt1[s1[i]];
        pos1[s1[i]].push_back(i);
    }
    vector<unsigned int> cnt2(256, 0);
    vector<deque<unsigned int>> pos2(256);
    for (unsigned int i = 0; i < s2.size(); ++i) {
        ++cnt2[s2[i]];
        pos2[s2[i]].push_back(i);
    }

    unsigned int cur1 = 0;
    unsigned int cur2 = 0;
    while (cur1 < s1.size() && cur2 < s2.size()) {
        char next_sym = 0;
        for (char c = 'z'; c >= 'a'; --c) {
            if (cnt1[c] > 0 && cnt2[c] > 0) {
                next_sym = c;
                unsigned int p1 = pos1[c].front();
                unsigned int p2 = pos2[c].front();
                unsigned int new_cur1 = p1 + 1;
                unsigned int new_cur2 = p2 + 1;
                for (int i = cur1; i < new_cur1; ++i) {
                    --cnt1[s1[i]];
                    pos1[s1[i]].pop_front();
                }
                for (int i = cur2; i < new_cur2; ++i) {
                    --cnt2[s2[i]];
                    pos2[s2[i]].pop_front();
                }
                cur1 = new_cur1;
                cur2 = new_cur2;
                break;
            }
        }
        if (!next_sym) {
            break;
        } else {
            res += next_sym;
        }
    }
    cout << res << endl;

    return 0;
}
