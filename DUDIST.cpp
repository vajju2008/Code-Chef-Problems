// We track the state going bottom-up for each subtree root u.
// Let dp[u][k][C][S] be the number of ways to color the subtree at u


#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int N, K, D;
vector<vector<int>> adj;
int sz[105];
// dp[u][red_count][color][S + D]
int dp[105][105][2][205];
int nxt_dp[105][2][205];

// Core mathematical rule for combining a budget and a requirement
inline int combine(int S1, int S2) {
    if (S1 >= 0 && S2 >= 0) return max(S1, S2);
    if (S1 < 0 && S2 < 0) return min(S1, S2);
    if (S1 >= 0 && S2 < 0) {
        if (S1 + S2 >= -1) return S1;
        return S2;
    }
    if (S1 < 0 && S2 >= 0) {
        if (S1 + S2 >= -1) return S2;
        return S1;
    }
    return 0; 
}

void dfs(int u, int p) {
    sz[u] = 1;
    
    // Initialize current node as a single-vertex subtree
    for(int k=0; k<=N; ++k)
        for(int C=0; C<2; ++C)
            for(int S=0; S<=2*D; ++S)
                dp[u][k][C][S] = 0;
    
    // An isolated node is uncovered, leaving a requirement of depth 0 -> S = -1
    dp[u][1][0][-1 + D] = 1; // Colored Red
    dp[u][0][1][-1 + D] = 1; // Colored Blue

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);

        for(int k=0; k<=sz[u]+sz[v]; ++k)
            for(int C=0; C<2; ++C)
                for(int S=0; S<=2*D; ++S)
                    nxt_dp[k][C][S] = 0;

        // Precompute collapsed state sums for opposite colors
        vector<long long> W_B(sz[v] + 1, 0); // Sum of valid Blue configurations
        vector<long long> W_R(sz[v] + 1, 0); // Sum of valid Red configurations
        for(int kv=0; kv<=sz[v]; ++kv) {
            for(int Sv=-D; Sv<=D; ++Sv) {
                W_B[kv] = (W_B[kv] + dp[v][kv][1][Sv + D]) % MOD;
                W_R[kv] = (W_R[kv] + dp[v][kv][0][Sv + D]) % MOD;
            }
        }

        for(int ku=0; ku<=sz[u]; ++ku) {
            for(int Su=-D; Su<=D; ++Su) {
                int ways_u_red = dp[u][ku][0][Su + D];
                int ways_u_blue = dp[u][ku][1][Su + D];
                if (!ways_u_red && !ways_u_blue) continue;

                for(int kv=0; kv<=sz[v]; ++kv) {
                    
                    // Case 1: Parent Red, Child Blue (Opposite)
                    if (ways_u_red && W_B[kv]) {
                        int nS = combine(Su, D - 1);
                        nxt_dp[ku+kv][0][nS + D] = (nxt_dp[ku+kv][0][nS + D] + 1LL * ways_u_red * W_B[kv]) % MOD;
                    }
                    
                    // Case 2: Parent Red, Child Red (Same)
                    if (ways_u_red) {
                        for(int Sv=-D; Sv<=D; ++Sv) {
                            int ways_v = dp[v][kv][0][Sv + D];
                            if (!ways_v) continue;
                            if (Sv - 1 < -D) continue; // Uncoverable internal node drop
                            
                            int nS = combine(Su, Sv - 1);
                            nxt_dp[ku+kv][0][nS + D] = (nxt_dp[ku+kv][0][nS + D] + 1LL * ways_u_red * ways_v) % MOD;
                        }
                    }
                    
                    // Case 3: Parent Blue, Child Red (Opposite)
                    if (ways_u_blue && W_R[kv]) {
                        int nS = combine(Su, D - 1);
                        nxt_dp[ku+kv][1][nS + D] = (nxt_dp[ku+kv][1][nS + D] + 1LL * ways_u_blue * W_R[kv]) % MOD;
                    }
                    
                    // Case 4: Parent Blue, Child Blue (Same)
                    if (ways_u_blue) {
                        for(int Sv=-D; Sv<=D; ++Sv) {
                            int ways_v = dp[v][kv][1][Sv + D];
                            if (!ways_v) continue;
                            if (Sv - 1 < -D) continue; // Uncoverable internal node drop
                            
                            int nS = combine(Su, Sv - 1);
                            nxt_dp[ku+kv][1][nS + D] = (nxt_dp[ku+kv][1][nS + D] + 1LL * ways_u_blue * ways_v) % MOD;
                        }
                    }
                }
            }
        }

        // Apply newly computed states up
        sz[u] += sz[v];
        for(int k=0; k<=sz[u]; ++k)
            for(int C=0; C<2; ++C)
                for(int S=0; S<=2*D; ++S)
                    dp[u][k][C][S] = nxt_dp[k][C][S];
    }
}

void solve() {
    cin >> N >> K >> D;
    adj.assign(N + 1, vector<int>());
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    long long ans = 0;
    for (int C = 0; C < 2; ++C) {
        // Only accept states where all internal requirements are resolved (S >= 0)
        for (int S = 0; S <= D; ++S) {
            ans = (ans + dp[1][K][C][S + D]) % MOD;
        }
    }
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) solve();
    }
    return 0;
}