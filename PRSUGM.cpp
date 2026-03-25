#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int X, int N, const vector<int>& A) {
    vector<int> B(N + 1);
    for (int i = 1; i <= N; ++i) {
        B[i] = (A[i - 1] >= X ? 1 : 0);
    }

    vector<bool> dp(N + 1, false);
    dp[0] = false;
    
    if (N >= 1) dp[1] = B[1];
    if (N >= 2) dp[2] = B[1] | B[2];

    for (int i = 3; i <= N; ++i) {
        if (B[i]) {
            dp[i] = dp[i] | dp[i - 2];
        }
        if (B[i - 1] || B[i]) {
            dp[i] = dp[i] | dp[i - 3];
        }
    }
    
    return dp[N];
}

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> vals(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        vals[i] = A[i];
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int left = 0, right = vals.size() - 1;
    int ans = vals[0];

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(vals[mid], N, A)) {
            ans = vals[mid];
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
