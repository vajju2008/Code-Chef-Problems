#include <bits/stdc++.h>

using namespace std;


using ll = long long;

const int MOD = 998244353; // moduloo 

vector<vector<int>> adj;

vector<int> par, sz;

vector<bool> is_path;

vector<ll> p2;


ll power(ll base, ll exp) {
    ll res = 1;
    
    base %= MOD;
    
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        
        base = (base * base) % MOD;
        
        exp /= 2;
    }
    return res;
    
}

void dfs(int u, int p) {
    sz[u] = 1;
    
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
            
        }
    }
}

void solve() {
    int n;
    
    if (!(cin >> n)) return;
    

    adj.assign(n + 1, vector<int>());
    par.assign(n + 1, 0);
    
    sz.assign(n + 1, 0);
    
    is_path.assign(n + 1, false); // false 

    if (p2.size() <= n) {
        p2.resize(n + 1);
        
        p2[0] = 1;
        for (int i = 1; i <= n; ++i) 
            p2[i] = (p2[i - 1] * 2) % MOD;
            
    }

    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
        par[i] = p;
    }

    vector<int> path;
    int curr = n;
    while (curr != 0) {
        path.push_back(curr);
        is_path[curr] = true;
        if (curr == 1) break;
        curr = par[curr];
    }
    reverse(path.begin(), path.end());

    dfs(1, 0);

    ll ans = 0;

    for (int i = 2; i <= n; ++i) {
        if (!is_path[i]) {
            ll ways = (p2[n] - p2[n - sz[i]] + MOD) % MOD;
            ll cost = (2 * ways) % MOD; // 2* ways
            
            ans = (ans + cost) % MOD;
            
        }
    }

    int m = path.size() - 1;
    
    if (m > 0) {
        vector<int> q;
        int q_start = sz[path[0]] - sz[path[1]]; 
        
        int q_end = sz[path[m]];  
        
        ll factor = p2[q_start + q_end];

        for (int i = 1; i < m; ++i) {
            int u = path[i];
            int next_node = path[i+1];
            q.push_back(sz[u] - sz[next_node]);
        }

        ll sum_ck = 0;

        for (int k = 1; k < m; ++k) {
            deque<ll> dp;
            dp.push_back(1);
            ll cur_sum = 1;

            for (int val : q) {
                ll active = (p2[val] - 1 + MOD) % MOD;
                ll next_zero = (cur_sum * active) % MOD;
                
                dp.push_front(next_zero);
                cur_sum = (cur_sum + next_zero) % MOD;
                
                if (dp.size() > k) {
                    ll invalid = dp.back();
                    dp.pop_back();
                    cur_sum = (cur_sum - invalid + MOD) % MOD;
                }
            }
            
            ll ck = (cur_sum * factor) % MOD;
            
            sum_ck = (sum_ck + ck) % MOD;
            
        }
        
        ans = (ans + 2 * sum_ck) % MOD;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); // sync_with_stdio flse 
    cin.tie(NULL);
    
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}