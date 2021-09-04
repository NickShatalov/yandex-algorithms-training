#include <iostream>

using namespace std;


int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a == 0) {
        if (b == 0) {
            cout << "INF" << endl;
            return 0;
        }
        cout << "NO" << endl;
        return 0;
    }

    if (-b % a != 0) {
        cout << "NO" << endl;
        return 0;
    }

    if (c == 0 || -b / a != -d / c) {
        cout << -b / a << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}
