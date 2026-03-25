#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    int n; // candies 
    cin >> n;
    
    map<int, int> counts;
    for (int i = 0; i < n; i++) {
        int color;
        cin >> color;
        counts[color]++;
    }

    int best_color = -1;
    
    int max_freq = -1;

    // Iterate through the maps
    for (auto const& [color, freq] : counts) {
        if (freq > max_freq) {
            max_freq = freq;
            best_color = color;
        } else if (freq == max_freq) {
            // Since we need the smallest color  we check
            if (best_color == -1 || color < best_color) {
                best_color = color;
            }
        }
    }
    
    cout << best_color << endl;
}

int main() {
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}