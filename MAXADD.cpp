#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests--) {
        int n;
        long long m;
        cin >> n >> m;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        for (int i = 0; i < n; i++) cin >> b[i];

        long long running = 0;
        long long limit = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            running += b[i];
            long long candidate = a[i] - running;
            if (candidate > limit)
                limit = candidate;
        }

        long long baseAdd = running;
        long long result = 0;

        if (limit >= 1) {
            long long fixedCount = min(m, limit);
            result += fixedCount * (baseAdd + limit);

            if (m > limit) {
                long long freeCount = m - limit;
                long long sumRange = (limit + 1 + m) * freeCount / 2;
                result += freeCount * baseAdd + sumRange;
            }
        } else {
            long long sumAll = (1 + m) * m / 2;
            result = m * baseAdd + sumAll;
        }

        cout << result << "\n";
    }

    return 0;
}
