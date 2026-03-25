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

        vector<long long> degSum(n + 1, 0);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            degSum[u] += w;
            degSum[v] += w;
        }

        long long ans = LLONG_MAX;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, degSum[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}
