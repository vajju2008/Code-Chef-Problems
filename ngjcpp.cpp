#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        int k;
        cin >> n >> k;

        if (k % 2 == 1) {
            for (int i = 0; i < k; i++) {
                cout << n << " ";
            }
        } else {
            for (int i = 0; i < k - 1; i++) {
                cout << n << " ";
            }
            cout << 0;
        }
        cout << "\n";
    }
    return 0;
}

