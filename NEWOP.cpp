#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        // dp_min[i][j] = min value for subarray A[i..j]
        // dp_max[i][j] = max value for subarray A[i..j]
        vector<vector<long long>> dp_min(N, vector<long long>(N));
        vector<vector<long long>> dp_max(N, vector<long long>(N));
        
        for (int i = 0; i < N; i++) {
            dp_min[i][i] = dp_max[i][i] = A[i];
        }
        
        // Length of interval
        for (int len = 2; len <= N; len++) {
            for (int i = 0; i <= N - len; i++) {
                int j = i + len - 1;
                long long mn = LLONG_MAX;
                long long mx = LLONG_MIN;
                
                // Try all possible merge positions k: merge [i..k] and [k+1..j]
                for (int k = i; k < j; k++) {
                    long long left_min = dp_min[i][k];
                    long long left_max = dp_max[i][k];
                    long long right_min = dp_min[k+1][j];
                    long long right_max = dp_max[k+1][j];
                    
                    // Possible values: left + 2*right
                    vector<long long> candidates = {
                        left_min + 2 * right_min,
                        left_min + 2 * right_max,
                        left_max + 2 * right_min,
                        left_max + 2 * right_max
                    };
                    
                    for (auto val : candidates) {
                        mn = min(mn, val);
                        mx = max(mx, val);
                    }
                }
                dp_min[i][j] = mn;
                dp_max[i][j] = mx;
            }
        }
        
        cout << dp_min[0][N-1] << " " << dp_max[0][N-1] << "\n";
    }
    return 0;
}