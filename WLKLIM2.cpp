#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

vector<vector<int>> adj;
vector<int> path;
vector<bool> is_on_path;

bool find_path(int u, int target, int p) {
    path.push_back(u);
    if (u == target) return true;
    
    for (int v : adj[u]) {
        if (v != p) {
            if (find_path(v, target, u)) return true;
        }
    }
    
    path.pop_back();
    return false;
}

int get_component_size(int u, int p) {
    int size = 1;
    for (int v : adj[u]) {
        if (v != p && !is_on_path[v]) {
            size += get_component_size(v, u);
        }
    }
    return size;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    adj.assign(N + 1, vector<int>());
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    path.clear();
    find_path(1, N, -1);

    is_on_path.assign(N + 1, false);
    for (int u : path) {
        is_on_path[u] = true;
    }

    vector<int> S;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        S.push_back(get_component_size(path[i], -1));
    }

    int K = S.size();
    if (K == 0) {
        cout << 0 << endl;
        return;
    }

    vector<long long> dp(K + 1);
    
    dp[0] = 1;
    
    for (int i = 0; i < K; ++i) {
        long long current_ways = (dp[i] * S[i]) % MOD;
        
        if (i > 0) {
            current_ways = (current_ways + dp[i-1]) % MOD;
        }
        
        dp[i+1] = current_ways;
    }

    cout << dp[K] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}