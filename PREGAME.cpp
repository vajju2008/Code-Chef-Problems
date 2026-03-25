#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long xr = a[n - 1];
        for (int i = 0; i < n - 1; i++) {
            xr ^= (a[i] - a[i + 1]);
        }

        if (xr == 0)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }

    return 0;
}
