#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; // n , vertices 


vector<int> V;

vector<vector<int>> adj; // adjacent 

vector<vector<int>> children; // childern s

vector<vector<int>> oss; //


void build_tree(int u, int p) {
    for (int v : adj[u]) {
        if (v != p) {
            children[u].push_back(v);
            
            
            build_tree(v, u);
            
            
        }
    }
}

void compute_oss(int u) {
    for (int v : children[u]) {
        compute_oss(v);
        
    }

    vector<int> result;
    
    
    result.push_back(V[u-1]);
    

    vector<int> candidates = children[u];
    

    while (!candidates.empty()) {
        
        int best_idx = -1;
        
        for (int i = 0; i < candidates.size(); ++i) {
            int curr = candidates[i];
            if (best_idx == -1) {
                best_idx = i;
                continue;
            }
            int best = candidates[best_idx];
            if (V[curr-1] < V[best-1]) {
                best_idx = i;
            } else if (V[curr-1] == V[best-1]) {
                const vector<int>& A = oss[curr];
                
                
                
                const vector<int>& B = oss[best];
                
                bool a_better = false; // if a is best  
                
                bool b_better = false; // if b is best 
                
                size_t nA = A.size();// size of a 
                
                size_t nB = B.size();// size of b 
                
                for (size_t k = 0; k < nA + nB; ++k) {
                    
                    int val1 = (k < nA) ? A[k] : B[k - nA];
                    
                    int val2 = (k < nB) ? B[k] : A[k - nB];
                    
                    if (val1 < val2) {
                        a_better = true;
                        break;
                    }
                    if (val1 > val2) {
                        b_better = true;
                        break;
                    }
                }
                if (a_better) {
                    best_idx = i;
                }
            }
        }
        int chosen = candidates[best_idx];
        
        result.push_back(V[chosen-1]);
        
        candidates[best_idx] = candidates.back();
        candidates.pop_back();
        
        
        for (int child : children[chosen]) {
            
            candidates.push_back(child);
            
        }
    }
    oss[u] = result;
    // Start result = [5].

//andidates = {2,3}.

//Compare values: 2 greater than  3 pick 2 result =5,2

////Add children of 2 

///Candidates= 3

//Pick 3 →result= 5,2,3
    
    
}

void solve() {
    if (!(cin >> N)) return;
    
    
    V.resize(N);
    
    for (int i = 0; i < N; ++i) cin >> V[i];
    
    
    adj.assign(N + 1, vector<int>());
    
    children.assign(N + 1, vector<int>());
    
    oss.assign(N + 1, vector<int>());
    
    
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        
        cin >> u >> v;
        
        adj[u].push_back(v);
        
        
        adj[v].push_back(u);
        
        
        
        
        
    }
    build_tree(1, 0); // tres 1,0 
    compute_oss(1);
    
    
    for (int i = 0; i < N; ++i) {
        
        cout << oss[1][i] << (i == N - 1 ? "" : " ");
        
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); // flase 
    cin.tie(NULL); // char tpo null 
    int t;
    if (cin >> t) {
        while (t--) {
            solve(); // slove the maths equations 
        }
    }
    return 0; // N=3
//V = [5, 2, 3]
// no of edges 1-2, 1-3

}
