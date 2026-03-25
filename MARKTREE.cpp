#include <iostream>

#include <vector>

#include <string>


#include <algorithm>

using namespace std; // namespace

void solve() {
    int N;
    if (!(cin >> N)) return; // it return to 1 

    vector<int> par(N + 1, 0);
    
    for (int i = 2; i <= N; ++i) {
        cin >> par[i];
        
    }

    string X;
    
    cin >> X;

    vector<int> path_nodes;
    vector<bool> on_path(N + 1, false);
    
    int curr = N;
    while (curr != 0) {
        path_nodes.push_back(curr);
        on_path[curr] = true;
        
        if (curr == 1) break;
        
        curr = par[curr];
    }
    
    reverse(path_nodes.begin(), path_nodes.end());

    vector<bool> needs_visit(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        
        if (X[i-1] == '1') {
            needs_visit[i] = true;
        }
    }

    long long base_cost = 0;

    for (int i = N; i >= 2; --i) {
        if (on_path[i]) {
            continue;
        }

        if (needs_visit[i]) {
            base_cost += 2;
            
            needs_visit[par[i]] = true;
            
        }
    }

    vector<int> active_indices; 
    for (int i = 0; i < path_nodes.size(); ++i) {
        int u = path_nodes[i];
        if (needs_visit[u]) {
            active_indices.push_back(i);
        }
    }

    if (active_indices.empty()) {
        cout << 0 << "\n";
        return;
    }

    long long min_path_cost = -1; 
    
    int m = active_indices.size();
    
    int path_len = path_nodes.size(); 
    

    for (int k = 0; k <= m; ++k) {
        long long current_cost = 0;
        
        if (k > 0) {
            current_cost += 2LL * active_indices[k-1];
            
        }

        if (k < m) {
            current_cost += 2LL * (path_len - 1 - active_indices[k]);
        }

        if (min_path_cost == -1 || current_cost < min_path_cost) {
            min_path_cost = current_cost;
        }
    }

    cout << base_cost + min_path_cost << "\n"; // min_path_cost lesser
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // nullptr
    
    

    int T;
    if (cin >> T) {
        while (T--) { // while loops to slove 
            
            solve();
        }
    }
    return 0;
}