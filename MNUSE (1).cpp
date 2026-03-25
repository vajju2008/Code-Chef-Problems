#include <iostream>
#include <algorithm>

using namespace std;

bool check(long long S_prime, long long K_prime, long long N, long long M) {
    if (K_prime == 0) return S_prime == 0;
    if (S_prime < 0) return false;
    if (N == 1) return false;
    if (M == 1) return (S_prime >= K_prime * 2LL && S_prime <= K_prime * N);
    if (M == N) return (S_prime >= K_prime * 1LL && S_prime <= K_prime * (N - 1LL));

    long long num_min = S_prime - K_prime * (M - 1LL);
    long long den = N - M + 1LL;
    long long y_min;
    if (num_min > 0) {
        y_min = (num_min + den - 1) / den;
    } else {
        y_min = num_min / den;
    }

    long long num_max = S_prime - K_prime;
    long long y_max;
    if (num_max >= 0) {
        y_max = num_max / M;
    } else {
        y_max = num_max / M;
        if (num_max % M != 0) y_max--;
    }

    long long left = max(0LL, y_min);
    long long right = min(K_prime, y_max);
    return left <= right;
}

void solve() {
    long long n, k, s, m;
    cin >> n >> k >> s >> m;
    
    for (long long c = 0; c <= k; ++c) {
        if (check(s - c * m, k - c, n, m)) {
            cout << c << "\n";
            return;
        }
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