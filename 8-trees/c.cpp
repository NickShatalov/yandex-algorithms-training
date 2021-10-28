#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    vector<vector<size_t>> g1(n);
    vector<vector<size_t>> g2(n);
    for (size_t i = 0; i < n; ++i) {
        size_t a;
        cin >> a;
        --a;
        g1[i].push_back(a);
        g2[a].push_back(i);
    }

    vector<bool> visited(n, false);
    vector<size_t> res;

    for (size_t i = 0; i < n; ++i) {
        if (visited[i]) {
            continue;
        }
        vector<bool> tmp(n, false);
        deque<size_t> st;
        st.push_back(i);
        size_t last;
        while (!st.empty()) {
            size_t v = st.front();
            last = v;
            st.pop_front();
            tmp[v] = true;
            for (auto u : g1[v]) {
                if (tmp[u]) {
                    continue;
                }
                st.push_back(u);
            }
        }
        st.push_back(last);
        res.push_back(last);
        while (!st.empty()) {
            size_t v = st.front();
            st.pop_front();
            visited[v] = true;
            for (auto u : g2[v]) {
                if (visited[u]) {
                    continue;
                }
                st.push_back(u);
            }
        }
    }

    cout << res.size() << endl;

    return 0;
}
