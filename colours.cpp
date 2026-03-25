#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

// Use a large value for negative infinity to avoid overflow issues.
const long long INF = 4e18; 

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> w(n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) cin >> w[i];
    for (int i = 0; i < n; ++i) cin >> c[i];

    // Map from a stored value to the set of colors with that value.
    map<long long, set<int>> val_to_colors;
    // Vector to find the stored value for a given color.
    vector<long long> color_to_val(n);
    // Global offset to apply to all stored values.
    long long offset = 0;

    // Initial state: At city 1, color 0 has 0 profit, others have -INF.
    color_to_val[0] = 0;
    val_to_colors[0].insert(0);
    for (int i = 1; i < n; ++i) {
        color_to_val[i] = -INF;
        val_to_colors[-INF].insert(i);
    }

    // Loop for moves to cities 2 through N.
    for (int i = 1; i < n; ++i) {
        // Find the real maximum profit.
        long long max_val = val_to_colors.rbegin()->first;
        long long max_prof_real = max_val + offset;

        // Calculate the threshold value for changing colors.
        long long V_real = max_prof_real - k;
        long long V_val = V_real - offset;
        
        // Merge all groups with profits less than the threshold.
        auto it_end_merge = val_to_colors.lower_bound(V_val);
        set<int> merged_colors;
        vector<long long> vals_to_erase;

        for (auto it = val_to_colors.begin(); it != it_end_merge; ++it) {
            merged_colors.insert(it->second.begin(), it->second.end());
            vals_to_erase.push_back(it->first);
        }

        for (long long val : vals_to_erase) {
            val_to_colors.erase(val);
        }

        if (!merged_colors.empty()) {
            val_to_colors[V_val].insert(merged_colors.begin(), merged_colors.end());
            for (int color : merged_colors) {
                color_to_val[color] = V_val;
            }
        }
        
        // Apply the base penalty for moving by updating the offset.
        offset -= w[i];

        // Apply the bonus for the preferred color by moving it to a new group.
        int pref_color = c[i];
        long long old_val = color_to_val[pref_color];
        long long new_val = old_val + 2 * w[i];

        val_to_colors[old_val].erase(pref_color);
        if (val_to_colors[old_val].empty()) {
            val_to_colors.erase(old_val);
        }
        val_to_colors[new_val].insert(pref_color);
        color_to_val[pref_color] = new_val;
    }
    
    // The final answer is the max stored value plus the final offset.
    cout << val_to_colors.rbegin()->first + offset << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
