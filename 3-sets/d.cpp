#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int max_bet = 100;

int main() {
    int n;
    cin >> n;

    vector<int> points(n);
    vector<int> numbers(n);

    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> numbers[i];
    }
    vector<int> bets(100, 0);

    for (int i = 0; i < n - 1; ++i) {
        ++bets[numbers[i] - 1];
    }
    int res = 0;
    int players_lost = n;
    for (int i = 1; i <= max_bet + 1; ++i) {
        numbers[n - 1] = i;
        if (i == max_bet + 1) {
            i = max(i, *max_element(points.begin(), points.end() - 1) -
                           points[n - 1] + 1);
        }
        int cur_players_lost = 0;
        int our_points = points[n - 1];
        int win_player = -1;
        ++bets[i - 1];
        for (int j = 0; j < n; ++j) {
            if (bets[numbers[j] - 1] == 1 && (win_player == -1 || numbers[j] < numbers[win_player])) {
                win_player = j;
            }
        }
       --bets[i - 1];
        if (!bets[i - 1] && win_player == n - 1) {
            our_points += i;
        }
        for (int j = 0; j < n - 1; ++j) {
            if ((j != win_player && our_points <= points[j]) ||
                (j == win_player && our_points <= points[j] + numbers[j])) {
                ++cur_players_lost;
            }
        }
        if (cur_players_lost < players_lost) {
            res = i;
            players_lost = cur_players_lost;
        }
    }
    cout << res << endl;

    return 0;
}
