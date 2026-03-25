#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 2) {
            p.push_back(i + 1);
        }
    }

    int k = p.size();
    
    if (k == 0) {
        cout << 0 << "\n";
        return;
    }

    if (k % 2 != 0) {
        long long cost = n - p[k - 1];
        for (int i = 0; i < (k - 1) / 2; ++i) {
            cost += (p[2 * i + 1] - p[2 * i] - 1);
        }
        cout << cost << "\n";
    } else {
        long long cost0 = 0;
        vector<long long> C(k / 2);
        for (int i = 0; i < k / 2; ++i) {
            C[i] = p[2 * i + 1] - p[2 * i] - 1;
            cost0 += C[i];
        }

        vector<long long> D(k / 2 - 1);
        long long sumD = 0;
        for (int i = 0; i < k / 2 - 1; ++i) {
            D[i] = p[2 * i + 2] - p[2 * i + 1] - 1;
            sumD += D[i];
        }

        long long min_S = sumD;
        long long current_S = sumD;

        for (int q = 0; q < k / 2 - 1; ++q) {
            current_S += C[q];
            current_S -= D[q];
            if (current_S < min_S) {
                min_S = current_S;
            }
        }

        long long cost1 = min_S + (n - p[k - 1]);
        cout << min(cost0, cost1) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
