#include <iostream>
#include <string>

using namespace std;

int main() {
    string x, z;
    cin >> x >> z;
    string y = "";
    int i = x.size() - 1;
    int j = z.size() - 1;
    string cache = "";

    while (j >= 0) {
        if (x[i] != z[j]) {
            i = x.size() - 1;
            y = z[j] + cache + y;
            cache = "";
            --j;
        } else {
            cache = z[j] + cache;
            --i;
            if (i < 0) {
                i = x.size() - 1;
            }
            --j;
        }
    }
    cout << y << endl;

    return 0;
}
