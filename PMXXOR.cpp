// By linearity of expectation, we can consider each of the 30 bits independently
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 998244353; //  across all distinct rearrangements of rearrangements of a 
const int MAX = 1000005;
long long fact[MAX], invFact[MAX];
long long power(long long base, long long exp) { // faster expa
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
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    } // // Precomputes factorials for O(1) combinations
    invFact[MAX - 1] = modInverse(fact[MAX - 1]);
    for (int i = MAX - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0; // r  is greater than or r is lesser then n 
    long long num = fact[n];
    long long den = (invFact[r] * invFact[n - r]) % MOD;
    return (num * den) % MOD;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> vals;
    vector<int> freqs;
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            vals.push_back(a[i]);
            freqs.push_back(1);
        } else {
            freqs.back()++;
        }
    }
    int m = vals.size();
    vector<long long> E(m);
    int S = 0;
    for (int i = m - 1; i >= 0; i--) {
        int f = freqs[i];
        if (S == 0) {
            E[i] = (f % 2 == 1) ? (MOD - 1) : 1;
        } else {
            long long sum = 0;
            for (int k = 0; k <= f; k++) {
                long long term = nCr(S - 1 + f - k, S - 1);
                if (k % 2 == 1) {
                    term = (MOD - term) % MOD;
                }
                sum = (sum + term) % MOD;
            }
            long long den_inv = (invFact[S + f] * fact[S]) % MOD;
            den_inv = (den_inv * fact[f]) % MOD;
            
            E[i] = (sum * den_inv) % MOD;
        }
        S += f;
    }

    long long ans = 0;
    long long inv2 = modInverse(2);
    for (int b = 0; b < 30; b++) {
        long long V = 1;
        bool has_bit = false;
        
        for (int i = 0; i < m; i++) {
            if ((vals[i] >> b) & 1) {
                V = (V * E[i]) % MOD;
                has_bit = true;
            }
        }
        if (!has_bit) continue;
        long long P = (1 - V + MOD) % MOD;
        P = (P * inv2) % MOD;

        long long val = (1LL << b) % MOD;
        long long expected_contrib = (P * val) % MOD;
        ans = (ans + expected_contrib) % MOD;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();    // Standard I/O optimization
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}