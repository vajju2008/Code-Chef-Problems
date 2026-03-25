#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long x;
        cin >> x;
 // is even 
        if (x % 4 == 0 || x == 1 || x == 2 || x == 3 || x == 6) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
