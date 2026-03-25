#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long A, B;
        cin >> A >> B;

        long long smallValue = 100 * B;
        long long largeValue = 225 * A;

        if (smallValue > largeValue) {
            cout << "Small\n";
        } else if (smallValue < largeValue) {
            cout << "Large\n";
        } else {
            cout << "Equal\n";
        }
    }

    return 0;
}
