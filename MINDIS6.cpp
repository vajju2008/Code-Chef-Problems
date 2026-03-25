#include <iostream>

#include <vector>

#include <map> // mapping

#include <algorithm>

using namespace std;

void solve() {
    int N; // integers 
    long long K;
    cin >> N >> K;

    vector<int> A(N);
    map<int, int> freq_map;

    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Aj = A$
        freq_map[A[i]]++;
    }

    int fixed_val = A[0];
    
    vector<int> removable_freqs;
    
    int distinct_count = freq_map.size();

    for (auto const& [val, count] : freq_map) {
        if (val != fixed_val) {
            removable_freqs.push_back(count);
        }
    }

    sort(removable_freqs.begin(), removable_freqs.end());

    for (int cost : removable_freqs) {
        if (K >= cost) {
            K -= cost;
            distinct_count--;
        } else {
            break;
        }
    }

    cout << distinct_count << endl;
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