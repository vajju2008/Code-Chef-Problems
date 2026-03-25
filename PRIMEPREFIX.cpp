#include <iostream>

#include <vector>

#include <cmath>

#include <algorithm>

using namespace std;

const int MAX_SUM = 10005;
bool is_prime[MAX_SUM];

void sieve() {
    fill(is_prime, is_prime + MAX_SUM, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAX_SUM; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAX_SUM; i += p)
                is_prime[i] = false;
        }
    }
}

void solve() {
        
    int N;// prime numbers
    cin >> N;
    vector<int> A(N);
    vector<int> pos1;
    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] == 1) {
            pos1.push_back(i);
            cnt1++;
        } else {
            cnt2++;
        }
    }

    vector<vector<pair<int, int>>> dp(cnt1 + 1, vector<pair<int, int>>(cnt2 + 1, {-1, -2e9}));

    dp[0][0] = {0, 0};

    for (int i = 0; i <= cnt1; ++i) {
        for (int j = 0; j <= cnt2; ++j) {
            if (dp[i][j].first == -1) continue;

            int current_primes = dp[i][j].first;
            int current_neg_cost = dp[i][j].second;
            int current_sum = i + j * 2;
            int current_idx = i + j;

            if (i < cnt1) {
                int next_sum = current_sum + 1;
                int added_prime = is_prime[next_sum] ? 1 : 0;
                int cost_inc = abs(pos1[i] - current_idx);
                
                pair<int, int> next_val = {current_primes + added_prime, current_neg_cost - cost_inc};
                
                if (next_val > dp[i + 1][j]) {
                    dp[i + 1][j] = next_val;
                }
            }

            if (j < cnt2) {
                int next_sum = current_sum + 2;
                int added_prime = is_prime[next_sum] ? 1 : 0;
                
                pair<int, int> next_val = {current_primes + added_prime, current_neg_cost};
                
                if (next_val > dp[i][j + 1]) {
                    dp[i][j + 1] = next_val;
                }
            }
        }
    }

    cout << -dp[cnt1][cnt2].second << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}