#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n, long long mod) {
    return power(n, mod - 2, mod);
}

void solve() {
    int N;
    long long P;
    if (!(cin >> N >> P)) return;

    // Prod[k][u] stores product of ways for indices 1..u to have reach <= k
    // Ways for single index v to have reach <= k is min(N, max(0, k - v))
    // Indices are 1-based
    vector<vector<long long>> Prod(N + 1, vector<long long>(N + 1));
    vector<vector<long long>> InvProd(N + 1, vector<long long>(N + 1));

    for (int k = 1; k <= N; ++k) {
        Prod[k][0] = 1;
        InvProd[k][0] = 1;
        for (int u = 1; u <= N; ++u) {
            long long cnt = 0;
            if (k - u > 0) {
                cnt = min((long long)N, (long long)k - u);
            }
            // If cnt is 0, the product becomes 0.
            // Since P is prime, we can store 0 directly.
            // However, we need to divide later. 
            // Note that for our transitions, we only divide by Prod[k][prev].
            // We only need valid transitions where cnt > 0 for all u in (prev, i].
            // So we can compute raw modular inverse. If base is 0, inv is 0 (logic handled in loop).
            
            Prod[k][u] = (Prod[k][u - 1] * cnt) % P;
            // Compute inverse only if strictly positive to avoid issues, 
            // though mathematically if it's 0, the path is invalid anyway.
            if (Prod[k][u] != 0)
                InvProd[k][u] = modInverse(Prod[k][u], P);
            else 
                InvProd[k][u] = 0; 
        }
    }

    // dp[i][prev] : count of ways to reach frontier i from frontier prev
    // S[i][prev]  : sum of distances
    vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, 0));
    vector<vector<long long>> S(N + 1, vector<long long>(N + 1, 0));

    dp[1][0] = 1;
    S[1][0] = 0;

    for (int i = 1; i < N; ++i) {
        for (int prev = 0; prev < i; ++prev) {
            if (dp[i][prev] == 0) continue;

            long long current_count = dp[i][prev];
            long long current_sum = S[i][prev];

            // Transition to j
            for (int j = i + 1; j <= N; ++j) {
                long long ways = 0;
                
                // Calculate ways to have max reach exactly j using indices (prev+1...i)
                if (j < N) {
                    // Need max(u + A_u) == j
                    // = Ways(<= j) - Ways(<= j-1)
                    
                    // Ways(<= j)
                    long long ways_j = 0;
                    // Check if range is valid (no zero counts)
                    // Prod[j][i] covers 1..i. We need prev+1..i.
                    // ways = Prod[j][i] / Prod[j][prev]
                    if (Prod[j][i] != 0 && InvProd[j][prev] != 0) {
                        ways_j = (Prod[j][i] * InvProd[j][prev]) % P;
                    }

                    // Ways(<= j-1)
                    long long ways_j_minus_1 = 0;
                    if (i < j - 1) { // Constraint: u <= i. if i >= j-1, then u can be j-1, count is 0.
                        if (Prod[j - 1][i] != 0 && InvProd[j - 1][prev] != 0) {
                            ways_j_minus_1 = (Prod[j - 1][i] * InvProd[j - 1][prev]) % P;
                        }
                    }

                    ways = (ways_j - ways_j_minus_1 + P) % P;
                } else {
                    // j == N
                    // Need max(u + A_u) >= N
                    // = Total - Ways(<= N-1)
                    
                    long long total_combinations = power(N, i - prev, P);
                    
                    long long ways_N_minus_1 = 0;
                    // Check validity for <= N-1
                    if (i < N - 1) {
                         if (Prod[N - 1][i] != 0 && InvProd[N - 1][prev] != 0) {
                            ways_N_minus_1 = (Prod[N - 1][i] * InvProd[N - 1][prev]) % P;
                        }
                    } else {
                        // If i >= N-1, then for u=N-1, max reach <= N-1 implies A_u <= 0 impossible
                        ways_N_minus_1 = 0;
                    }

                    ways = (total_combinations - ways_N_minus_1 + P) % P;
                }

                if (ways > 0) {
                    long long added_count = (current_count * ways) % P;
                    // Distance increases by 1
                    // New sum = (Sum_prev * ways) + (Count_prev * ways * 1)
                    long long added_sum = (current_sum * ways) % P;
                    added_sum = (added_sum + added_count) % P;

                    dp[j][i] = (dp[j][i] + added_count) % P;
                    S[j][i] = (S[j][i] + added_sum) % P;
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i < N; ++i) {
        if (S[N][i] > 0) {
            // Unused indices i+1...N can be anything
            long long unused_ops = power(N, N - i, P);
            long long term = (S[N][i] * unused_ops) % P;
            ans = (ans + term) % P;
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