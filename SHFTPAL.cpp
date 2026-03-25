// Loop through the array and track the elements. The first time you see an element, append it to Seq1. The second time you see it, append it to Seq2.
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(2 * n);
    // This will store the relative order (ID) of the first occurrences
    vector<int> first_appearance_id(n + 1, -1); 
    vector<int> v; // This represents our mapping sequence
    
    int current_id = 0;
    
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
        
        // If we haven't seen this number yet, assign it the next ID
        if (first_appearance_id[a[i]] == -1) {
            first_appearance_id[a[i]] = current_id++;
        } 
        // If we HAVE seen it, push its assigned ID to our sequence V
        else {
            v.push_back(first_appearance_id[a[i]]);
        }
    }
    
    // Find where the sequence bottoms out at 0
    int zero_idx = -1;
    for (int i = 0; i < n; ++i) {
        if (v[i] == 0) {
            zero_idx = i;
            break;
        }
    }
    
    bool is_balanced = true;
    
    // Check if everything before 0 is strictly decreasing
    for (int i = 1; i <= zero_idx; ++i) {
        if (v[i] > v[i - 1]) {
            is_balanced = false;
            break;
        }
    }
    
    // Check if everything after 0 is strictly increasing
    for (int i = zero_idx + 1; i < n; ++i) {
        if (v[i] < v[i - 1]) {
            is_balanced = false;
            break;
        }
    }
    
    // Output the result
    if (is_balanced) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // Fast I/O for competitive programming limits
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}