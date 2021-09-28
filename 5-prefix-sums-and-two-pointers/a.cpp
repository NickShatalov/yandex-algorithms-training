#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    const int clothes_num = 4;

    vector<vector<int>> colors(clothes_num);
    for (int i = 0; i < clothes_num; ++i) {
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;
            colors[i].push_back(tmp);
        }
        sort(colors[i].begin(), colors[i].end());
    }

    vector<int> cur_colors(clothes_num);
    for (int i = 0; i < clothes_num; ++i) {
        cur_colors[i] = colors[i][0];
    }
    int min_clothes = 0;
    int max_clothes = 0;
    for (int i = 0; i < clothes_num; ++i) {
        if (cur_colors[i] < cur_colors[min_clothes]) {
            min_clothes = i;
        }
        if (cur_colors[i] > cur_colors[max_clothes]) {
            max_clothes = i;
        }
    }
    int res = cur_colors[max_clothes] - cur_colors[min_clothes];
    vector<int> res_colors = cur_colors;
    vector<int> p(clothes_num, 0);
    int cur_style = res;
    while (true) {
        if (p[min_clothes] == colors[min_clothes].size() - 1) {
            break;
        }
        if (res == 0) {
            break;
        }
        ++p[min_clothes];
        cur_colors[min_clothes] = colors[min_clothes][p[min_clothes]];
        for (int i = 0; i < clothes_num; ++i) {
            if (cur_colors[i] < cur_colors[min_clothes]) {
                min_clothes = i;
            }
            if (cur_colors[i] > cur_colors[max_clothes]) {
                max_clothes = i;
            }
        }
        cur_style = cur_colors[max_clothes] - cur_colors[min_clothes];
        if (cur_style < res) {
            res = cur_style;
            res_colors = cur_colors;
        }
    }

    for (int i = 0; i < clothes_num; ++i) {
        cout << res_colors[i] << " ";
    }
    cout << endl;

    return 0;
}
