//It pops all elements $y$ in the stack where y < x
#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

// Fast modularszzexponentiation to mappses the time complexity 
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res; // retuen s to ress
}

void solve() { // no 0 value 
    int n;
    
    if (!(cin >> n)) return;
    
    vector<vector<int>> f(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> f[i][j];
        }
    }

    vector<int> P(n + 2, 0);
    
    // Compute P  v for v from 2 to N
    for (int v = 2; v <= n; ++v) { // already the value in co puter
        
        vector<int> valid_mask(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (f[i][j] < v) {
                    valid_mask[i] |= (1 << (j - 1));
                }
            }
        }

        vector<int> curr(1 << n, 0);
        curr[0] = 1;

        for (int len = 0; len < n; ++len) {
            vector<int> next_dp(1 << n, 0);
            for (int mask = 0; mask < (1 << n); ++mask) {
                if (!curr[mask]) continue;
                
                for (int x = 1; x <= n; ++x) {
                    // Extract elements that will be popped or pushed to anither array 
                    
                    int popped = mask & ((1 << x) - 1);
                    
                    // Fast check: Are all popped elmetzzzzzz
                    if ((popped & ~valid_mask[x]) != 0) continue;
                    
                    int unpopped = mask & ~((1 << x) - 1);
                    int next_greater = (unpopped == 0) ? 0 : __builtin_ctz(unpopped) + 1;
                    
                    // Check if the generates or not 
                    if (next_greater != 0 && ((valid_mask[x] & (1 << (next_greater - 1))) == 0)) continue;
                    
                    int nmask = unpopped | (1 << (x - 1));
                    next_dp[nmask] += curr[mask];
                    if (next_dp[nmask] >= MOD) next_dp[nmask] -= MOD;
                }
            }
            curr = move(next_dp);
        }

        long long total = 0;
        
        for (int mask = 0; mask < (1 << n); ++mask) {
            total += curr[mask];
        }
        P[v] = total % MOD;
    }

    P[n + 1] = power(n, n);

    // Apply the summation formulaeszz to the give function 
    long long ans = (1LL * n * P[n + 1]) % MOD;
    for (int v = 2; v <= n; ++v) {
        ans = (ans - P[v] + MOD) % MOD;
    }
    
    cout << ans << "\n";
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