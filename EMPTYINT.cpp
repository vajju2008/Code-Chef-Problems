#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        bool oneA = false, oneB = false;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 1) oneA = true;
        }

        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            if (x == 1) oneB = true;
        }

        if (oneA && oneB)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
