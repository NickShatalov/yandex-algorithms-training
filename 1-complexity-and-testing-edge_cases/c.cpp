// solved with 3rd attempt

#include <iostream>

using namespace std;


int main()
{
    int noughts = 0;
    int crosses = 0;
    int field[3][3];
    for (int i = 0; i < 9; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp == 1) {
            ++crosses;
        }
        if (tmp == 2) {
            ++noughts;
        }
        field[i / 3][i % 3] = tmp;
    }
    if (crosses != noughts && crosses != noughts + 1) {
        cout << "NO" << endl;
        return 0;
    }

    bool noughts_win = false;
    bool crosses_win = false;

    bool noughts_tmp = true;
    bool crosses_tmp = true;
    for (int i = 0; i < 3; ++i) {
        noughts_tmp &= field[i][i] == 2; 
        crosses_tmp &= field[i][i] == 1;  
    } 
    noughts_win |= noughts_tmp;
    crosses_win |= crosses_tmp;

    noughts_tmp = true;
    crosses_tmp = true;
    for (int i = 0; i < 3; ++i) {
        noughts_tmp &= field[i][2 - i] == 2; 
        crosses_tmp &= field[i][2 - i] == 1;  
    } 
    noughts_win |= noughts_tmp;
    crosses_win |= crosses_tmp;

    for (int i = 0; i < 3; ++i) {
        noughts_tmp = true;
        crosses_tmp = true;
        for (int j = 0; j < 3; ++j) {
            noughts_tmp &= field[i][j] == 2; 
            crosses_tmp &= field[i][j] == 1;  
        } 
        noughts_win |= noughts_tmp;
        crosses_win |= crosses_tmp;
    }

    for (int i = 0; i < 3; ++i) {
        noughts_tmp = true;
        crosses_tmp = true;
        for (int j = 0; j < 3; ++j) {
            noughts_tmp &= field[j][i] == 2; 
            crosses_tmp &= field[j][i] == 1;  
        } 
        noughts_win |= noughts_tmp;
        crosses_win |= crosses_tmp;
    }

    if ((noughts_win && crosses_win) ||
            (noughts_win && crosses != noughts) ||
            (crosses_win && crosses != noughts + 1)) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }

    return 0;
}
