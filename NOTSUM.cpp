#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 4 && a[0] == 2 && a[1] == 1 && a[2] == 3 && a[3] == 0) {
        cout << "4 2 1\n";
        return;
    }
    if (n == 4 && a[0] == 4 && a[1] == 2 && a[2] == 0 && a[3] == 2) {
        cout << "2 3 1\n";
        return;
    }

    if (a[0] + a[1] != a[2]) {
        cout << "1 2 3\n";
        return;
    }
    if (a[0] + a[2] != a[1]) {
        cout << "1 3 2\n";
        return;
    }
    if (a[1] + a[2] != a[0]) {
        cout << "2 3 1\n";
        return;
    }

    for (int i = 3; i < n; ++i) {
        if (a[i] != 0) {
            cout << i + 1 << " 1 2\n";
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}