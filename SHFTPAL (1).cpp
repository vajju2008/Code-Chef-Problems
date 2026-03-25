#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for(int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }

    vector<int> first_idx(n + 1, -1);
    vector<int> A;
    A.reserve(n);

    for(int i = 0; i < 2 * n; i++) {
        int val = a[i];
        if(first_idx[val] == -1) {
            first_idx[val] = i + 1;
        } else {
            A.push_back(first_idx[val]);
        }
    }

    vector<int> inc_suffix(n + 1, 0);
    inc_suffix[n] = 1;
    if(n >= 1) inc_suffix[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--) {
        inc_suffix[i] = inc_suffix[i + 1] && (A[i] < A[i + 1]);
    }

    vector<int> dec_prefix(n + 1, 0);
    dec_prefix[0] = 1;
    if(n >= 1) dec_prefix[1] = 1;
    for(int i = 2; i <= n; i++) {
        dec_prefix[i] = dec_prefix[i - 1] && (A[i - 2] > A[i - 1]);
    }

    bool possible = false;
    for(int k = 0; k <= n; k++) {
        if(dec_prefix[k] && inc_suffix[k]) {
            possible = true;
            break;
        }
    }

    if(possible) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}