#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

// Disjoint Set Union (DSU) structure for efficient connectivity checks
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

// Calculate the swap weight between two cells
long long get_dist(int r1, int c1, int r2, int c2) {
    return (long long)(abs(r1 - r2) + 1) * (abs(c1 - c2) + 1);
}

// Check function to verify if grid can be sorted with minimum swap cost X
bool check(int X, int N, int M, const vector<int>& p, const vector<int>& corner_indices) {
    int size = N * M;
    DSU dsu(size);
    
    // 1. Union corners with each other if they satisfy the condition
    for (size_t i = 0; i < corner_indices.size(); ++i) {
        for (size_t j = i + 1; j < corner_indices.size(); ++j) {
            int u = corner_indices[i];
            int v = corner_indices[j];
            int r1 = u / M, c1 = u % M;
            int r2 = v / M, c2 = v % M;
            
            if (get_dist(r1, c1, r2, c2) >= X) {
                dsu.unite(u, v);
            }
        }
    }
    
    // 2. Union every cell with the 4 corners if they satisfy the condition
    // We only need to check edges to corners because max distance from any node is always to a corner.
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            int u = r * M + c;
            for (int corner_idx : corner_indices) {
                int cr = corner_idx / M;
                int cc = corner_idx % M;
                if (get_dist(r, c, cr, cc) >= X) {
                    dsu.unite(u, corner_idx);
                }
            }
        }
    }
    
    // 3. Validation: Check if every element is in the same component as its target position
    for (int i = 0; i < size; ++i) {
        int val = p[i];     // Value at current position i
        int target = val - 1; // Target position (0-based) for this value
        
        if (i != target) {
            if (dsu.find(i) != dsu.find(target)) {
                return false;
            }
        }
    }
    
    return true;
}

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    
    vector<int> p(N * M);
    bool is_sorted = true;
    
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            int val;
            cin >> val;
            p[r * M + c] = val;
            // Check if grid is already sorted (1-based value vs 0-based index)
            if (val != r * M + c + 1) {
                is_sorted = false;
            }
        }
    }
    
    if (is_sorted) {
        cout << (long long)N * M + 1 << "\n";
        return;
    }
    
    // Identify the corner indices
    vector<int> corners;
    corners.push_back(0);                   // Top-Left
    corners.push_back(M - 1);               // Top-Right
    corners.push_back((N - 1) * M);         // Bottom-Left
    corners.push_back((N - 1) * M + M - 1); // Bottom-Right
    
    // Sort and remove duplicates (handles 1xM or Nx1 grids)
    sort(corners.begin(), corners.end());
    corners.erase(unique(corners.begin(), corners.end()), corners.end());
    
    // Binary Search for the maximum X
    int low = 1, high = N * M;
    int ans = 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid == 0) { // Safety check, though range starts at 1
            low = 1; 
            continue; 
        } 
        
        if (check(mid, N, M, p, corners)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while(T--) {
            solve();
        }
    }
    return 0;
}