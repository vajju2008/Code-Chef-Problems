#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


vector<long long> divisors; 

vector<vector<pair<int, int>>> adj; 

vector<vector<long long>> memo;

map<long long, int> val_to_idx;



long long dfs(int current_idx, int min_idx) {
    
    if (memo[current_idx][min_idx] != -1) {
        return memo[current_idx][min_idx];
    }

    
    long long count = 1;

   
    for (auto& edge : adj[current_idx]) {
        int factor_idx = edge.first;
        int remainder_idx = edge.second;

        
        
        if (factor_idx < min_idx) continue;

        
        count += dfs(remainder_idx, factor_idx);
    }

   
    return memo[current_idx][min_idx] = count;
}

void solve() {
    long long N;
    
    if (!(cin >> N)) return;
    

    if (N == 1) {
        cout << 1 << "\n";
        
        return;
    }

   
    divisors.clear();
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            divisors.push_back(i);
            
            if (i * i != N) {
                divisors.push_back(N / i);
                
            }
        }
    }
    sort(divisors.begin(), divisors.end());

    
    val_to_idx.clear();
    int D = divisors.size();
    for (int i = 0; i < D; ++i) {
        val_to_idx[divisors[i]] = i;
    }

    
    adj.assign(D, vector<pair<int, int>>());
    
    for (int i = 0; i < D; ++i) {
        long long val = divisors[i];
        
        for (int j = 1; j < D; ++j) {
            long long f = divisors[j];
            if (f * f > val) break; 

            if (val % f == 0) {
                long long rem = val / f;
                
                adj[i].push_back({j, val_to_idx[rem]});
            }
        }
    }

    
    memo.assign(D, vector<long long>(D, -1));

    
    cout << dfs(D - 1, 1) << "\n";
}

int main() {
    // Fast I/O
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

