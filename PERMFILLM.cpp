#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve_test_case() {
        
    int n;
    if (!(cin >> n)) return;

    vector<int> q(n);
    
    vector<int> loc(n, -1);
    
    vector<int> free_slots;
    

    for (int i = 0; i < n; ++i) {
        cin >> q[i];
        
        if (q[i] == -1) {
            free_slots.push_back(i);
        } else {
            loc[q[i]] = i;
        }
    }

    int m = free_slots.size();
    vector<long long> dp;
    
    dp.push_back(0);

    int min_f = n, max_f = -1;
    int used_cnt = 0;

    for (int val = 0; val < n; ++val) {

        if (loc[val] != -1) {
            min_f = min(min_f, loc[val]);
            max_f = max(max_f, loc[val]);
        }


        if (loc[val] == -1) {
            used_cnt++;
            int range_sz = m - used_cnt + 1;
            vector<long long> next_dp(range_sz);

            for (int i = 0; i < range_sz; ++i) {
                long long prev_best;
                if (used_cnt == 1) prev_best = dp[0];
                else prev_best = max(dp[i], dp[i + 1]);

                int l = min_f;
                int r = max_f;
                l = min(l, free_slots[i]);
                r = max(r, free_slots[i + used_cnt - 1]);

                next_dp[i] = prev_best + (long long)(l + 1) * (n - r);
            }
            dp = next_dp;
        } else {
            for (int i = 0; i < dp.size(); ++i) {
                int l = min_f;
                int r = max_f;

                if (used_cnt > 0) {
                    l = min(l, free_slots[i]);
                    r = max(r, free_slots[i + used_cnt - 1]);
                }

                dp[i] += (long long)(l + 1) * (n - r);
            }
        }
    }

    cout << dp[0] << "\n";
}

int main() {
        
    ios_base::sync_with_stdio(false);
    
    cin.tie(NULL);
    

    int t;
    if (cin >> t) {
            
        while (t--) {
                
            solve_test_case();
        }
    }
    return 0;
}