#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;

int cnt_sub_left[95][95];
int pos[95];

void solve() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        pos[P[i]] = i;
    }

    memset(cnt_sub_left, 0, sizeof(cnt_sub_left));
    for (int v = 1; v <= N; ++v) {
        for (int p = 0; p <= N; ++p) {
            int count = cnt_sub_left[v-1][p];
            if (pos[v] < p) {
                count++;
            }
            cnt_sub_left[v][p] = count;
        }
    }

    int max_coins = 0;

    for (int L = 1; L <= N; ++L) {
        for (int R = L; R <= N; ++R) {
            int subset_len = R - L + 1;
            
            vector<int> ns_indices;
            ns_indices.reserve(N);
            for(int i=0; i<N; ++i) {
                if (P[i] < L || P[i] > R) {
                    ns_indices.push_back(i);
                }
            }
            
            vector<int> ns_left(N + 1, 0);
            int current_ns_cnt = 0;
            int ns_ptr = 0;
            for(int p = 0; p <= N; ++p) {
                while(ns_ptr < ns_indices.size() && ns_indices[ns_ptr] < p) {
                    current_ns_cnt++;
                    ns_ptr++;
                }
                ns_left[p] = current_ns_cnt;
            }

            vector<int> dp(subset_len + 1, INF);
            dp[0] = 0;

            for (int k = 0; k < N; ++k) {
                vector<int> next_dp(subset_len + 1, INF);
                
                for (int j = 0; j <= subset_len && j <= k; ++j) {
                    if (dp[j] == INF) continue;
                    
                    int m = k - j;

                    if (j < subset_len) {
                        int val = L + j;
                        int p = pos[val];
                        
                        int placed_sub_left = cnt_sub_left[L + j - 1][p] - cnt_sub_left[L - 1][p];
                        int placed_ns_left = min(m, ns_left[p]);
                        
                        int cost = p - placed_sub_left - placed_ns_left;
                        next_dp[j + 1] = min(next_dp[j + 1], dp[j] + cost);
                    }

                    if (m < ns_indices.size()) {
                        int p = ns_indices[m];
                        
                        int placed_sub_left = cnt_sub_left[L + j - 1][p] - cnt_sub_left[L - 1][p];
                        int placed_ns_left = m;
                        
                        int cost = p - placed_sub_left - placed_ns_left;
                        next_dp[j] = min(next_dp[j], dp[j] + cost);
                    }
                }
                dp = next_dp;
            }

            int min_swaps = dp[subset_len];
            int current_score = subset_len - min_swaps;
            max_coins = max(max_coins, current_score);
        }
    }

    cout << max_coins << endl;
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