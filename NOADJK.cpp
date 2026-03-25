#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    if (K == 2) {
        long long minOdd = 2e18, maxOdd = -2e18;
        long long minEven = 2e18, maxEven = -2e18;
        bool hasOdd = false, hasEven = false;

        for (int i = 0; i < N; i++) {
            if ((i + 1) % 2 != 0) {
                minOdd = min(minOdd, A[i]);
                maxOdd = max(maxOdd, A[i]);
                hasOdd = true;
            } else {
                minEven = min(minEven, A[i]);
                maxEven = max(maxEven, A[i]);
                hasEven = true;
            }
        }

        long long ans = 0;
        if (hasOdd) ans = max(ans, maxOdd - minOdd);
        if (hasEven) ans = max(ans, maxEven - minEven);
        
        cout << ans << "\n";
        return;
    }

    vector<long long> preMin(N), preMax(N);
    vector<long long> sufMin(N), sufMax(N);

    preMin[0] = preMax[0] = A[0];
    for (int i = 1; i < N; i++) {
        preMin[i] = min(preMin[i-1], A[i]);
        preMax[i] = max(preMax[i-1], A[i]);
    }

    sufMin[N-1] = sufMax[N-1] = A[N-1];
    for (int i = N - 2; i >= 0; i--) {
        sufMin[i] = min(sufMin[i+1], A[i]);
        sufMax[i] = max(sufMax[i+1], A[i]);
    }

    long long maxScore = 0;

    for (int i = 0; i < N; i++) {
        if (i >= 2) {
            maxScore = max(maxScore, abs(A[i] - preMin[i-2]));
            maxScore = max(maxScore, abs(A[i] - preMax[i-2]));
        }
        if (i <= N - 3) {
            maxScore = max(maxScore, abs(A[i] - sufMin[i+2]));
            maxScore = max(maxScore, abs(A[i] - sufMax[i+2]));
        }
    }

    cout << maxScore << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}