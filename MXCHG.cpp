#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2000005;

long long fact[MAXN];
long long invFact[MAXN];
long long POW2[MAXN];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    POW2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        POW2[i] = (POW2[i - 1] * 2) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
    int N;
    if (!(cin >> N)) return;

    vector<int> cnt(N + 1, 0);
    int max_val = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a <= N) cnt[a]++;
        max_val = max(max_val, a);
    }

    vector<int> SuffCnt(2 * N + 5, 0);
    for (int i = N; i >= 0; i--) {
        SuffCnt[i] = SuffCnt[i + 1] + cnt[i];
    }

    vector<int> unique_counts;
    for (int i = 0; i <= max_val; i++) {
        if (cnt[i] > 0) unique_counts.push_back(cnt[i]);
    }
    sort(unique_counts.begin(), unique_counts.end());
    unique_counts.erase(unique(unique_counts.begin(), unique_counts.end()), unique_counts.end());

    vector<vector<long long>> W(N + 1);
    for (int c : unique_counts) {
        W[c].resize(c + 2);
        long long current_sum = 0;
        for (int j = c; j >= 1; j--) {
            current_sum = (current_sum + nCr(c, j)) % MOD;
            W[c][j] = current_sum;
        }
    }

    long long ans = 0;

    for (int j = 1; j <= N + 1; j++) {
        long long curr = 1;
        
        for (int K = 0; K <= N + 1; K++) {
            int suffix_idx = K + j;
            int s_cnt = (suffix_idx < SuffCnt.size()) ? SuffCnt[suffix_idx] : 0;
            
            long long suffix_ways;
            
            if (K <= 1) {
                if (s_cnt == 0) suffix_ways = 0;
                else suffix_ways = (POW2[s_cnt] - 1 + MOD) % MOD;
            } else {
                suffix_ways = POW2[s_cnt];
            }

            long long term = (curr * suffix_ways) % MOD;
            ans = (ans + term) % MOD;

            if (K == 0) {
                long long f = (POW2[cnt[0]] - 1 + MOD) % MOD;
                curr = (curr * f) % MOD;
            } else {
                if (K > N) {
                    curr = 0;
                } else {
                    int c = cnt[K];
                    if (j > c) curr = 0;
                    else curr = (curr * W[c][j]) % MOD;
                }
            }

            if (curr == 0) break;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}