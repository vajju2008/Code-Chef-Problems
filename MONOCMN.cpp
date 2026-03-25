#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

// Check feasibility for Case: Max X and Max Y have the SAME color (e.g., both Red).
// Logic applies symmetrically for Blue-Blue.
// Structure: X is split (Prefix B, Suffix R), Y is split (Prefix B, Suffix R).
bool check_same(int N, int M, const vector<ll>& X, const vector<ll>& Y, ll K) {
    // We need to find if there exist split points i (for X) and j (for Y) such that:
    // 1. (X[N-1] - X[i+1]) * Y[M-1] <= K   (Red X Span * Max Y Red)
    // 2. (Y[M-1] - Y[j+1]) * X[N-1] <= K   (Red Y Span * Max X Red)
    // 3. (X[i] - X[0]) * Y[j] <= K         (Blue X Span * Max Y Blue)
    // 4. (Y[j] - Y[0]) * X[i] <= K         (Blue Y Span * Max X Blue)
    
    // For 1 & 2: We want the smallest valid suffixes to minimize the "cost" for the prefix constraints (3 & 4).
    // Actually, larger suffix -> smaller prefix -> easier to satisfy 3 & 4.
    // But larger suffix -> harder to satisfy 1 & 2.
    // We calculate the minimum suffix length required (i.e., max split index i) for 1 & 2.
    
    // Find smallest i such that Suffix X[i+1...N-1] is valid for Cond 1.
    // As i increases, X[i+1] increases, Span decreases. So we need i >= min_i.
    int min_i = -1;
    int low = 0, high = N - 2;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if ((X[N-1] - X[mid+1]) * Y[M-1] <= K) {
            min_i = mid;
            high = mid - 1; // Try to see if smaller i works (larger suffix) - wait.
            // If mid works, it means span is small enough.
            // Smaller i means larger span.
            // We want the SMALLEST i that works? No.
            // For constraints 3 & 4, we want small X[i] and Y[j].
            // So we want smallest indices i and j that satisfy 1 and 2.
        } else {
            low = mid + 1; // Span too big, need larger i (smaller span)
        }
    }
    
    if (min_i == -1) return false;

    // Find smallest j for Cond 2
    int min_j = -1;
    low = 0; high = M - 2;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if ((Y[M-1] - Y[mid+1]) * X[N-1] <= K) {
            min_j = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    if (min_j == -1) return false;

    // Check cross constraints with the minimal valid indices
    if ((X[min_i] - X[0]) * Y[min_j] <= K && (Y[min_j] - Y[0]) * X[min_i] <= K) {
        return true;
    }
    
    return false;
}

// Check feasibility for Case: Max X is Red, Max Y is Blue.
// X: Prefix Blue, Suffix Red (Split at i)
// Y: Prefix Red, Suffix Blue (Split at j)
bool check_diff(int N, int M, const vector<ll>& X, const vector<ll>& Y, ll K) {
    // Constraints:
    // 1. (X[i] - X[0]) * Y[M-1] <= K          (Blue X Span * Max Y Blue)
    // 2. (Y[j] - Y[0]) * X[N-1] <= K          (Red Y Span * Max X Red)
    // 3. (X[N-1] - X[i+1]) * Y[j] <= K        (Red X Span * Max Y Red)
    // 4. (Y[M-1] - Y[j+1]) * X[i] <= K        (Blue Y Span * Max X Blue)
    
    // We iterate i from 0 to N-2.
    // Cond 1 limits max i.
    // For a fixed i, we need to find if there is a valid j in [0, M-2].
    // Valid j range is intersection of:
    // - j <= J_limit_2 (from Cond 2) [Constant]
    // - j <= J_limit_3 (from Cond 3) [Increases as i increases]
    // - j >= J_limit_4 (from Cond 4) [Increases as i increases]
    
    // Precompute J_limit_2
    int j_limit_2 = -1;
    int l = 0, r = M - 2;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if ((Y[mid] - Y[0]) * X[N-1] <= K) {
            j_limit_2 = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (j_limit_2 == -1) return false; // Even smallest Y Red span fails

    // Pointers for sliding window
    int j_limit_3 = -1; // Max j for Cond 3
    int j_min_4 = 0;    // Min j for Cond 4 (derived from k=j+1)
    
    // Initialize j_limit_3 for i=0 is unnecessary, can grow inside loop
    // Initialize j_min_4: we need smallest k (1..M-1) s.t. (Y[M-1] - Y[k]) * X[0] <= K.
    // j_min_4 = k - 1.
    // We update this dynamically.
    
    int k_ptr = 1;

    for (int i = 0; i < N - 1; ++i) {
        // Check Cond 1
        if ((X[i] - X[0]) * Y[M-1] > K) break; // i became too large
        
        // Update j_limit_3 (Upper bound)
        // We want max j such that Y[j] <= K / (X[N-1] - X[i+1])
        ll denom = X[N-1] - X[i+1];
        if (denom == 0) {
            j_limit_3 = M - 2; // Infinity allowed
        } else {
            // j_limit_3 is non-decreasing. Increment while valid.
            // Start from where we left off (or -1 if first iter)
            // But we must check against M-2 limit
            while(j_limit_3 < M - 2) {
                if (Y[j_limit_3 + 1] * denom <= K) {
                    j_limit_3++;
                } else {
                    break;
                }
            }
        }
        
        // Update j_min_4 (Lower bound)
        // We need smallest k s.t. (Y[M-1] - Y[k]) * X[i] <= K
        // As i increases, X[i] increases -> allowed span decreases -> Y[k] must increase -> k increases.
        while(k_ptr < M) {
            if ((Y[M-1] - Y[k_ptr]) * X[i] <= K) {
                break; 
            }
            k_ptr++;
        }
        if (k_ptr == M) break; // No valid k possible for this i or larger
        
        int current_j_min = k_ptr - 1;
        
        // Intersect ranges
        int current_j_max = min(j_limit_2, j_limit_3);
        
        if (current_j_min <= current_j_max) return true;
    }
    
    return false;
}

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    
    vector<ll> X(N), Y(M);
    for(int i = 0; i < N; ++i) cin >> X[i];
    for(int i = 0; i < M; ++i) cin >> Y[i];
    
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    
    ll low = 1, high = 4000000000000000000LL; // 4e18
    ll ans = high;
    
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        bool ok = false;
        
        // Check all 4 configurations
        if (check_same(N, M, X, Y, mid)) ok = true;
        else if (check_same(M, N, Y, X, mid)) ok = true;
        else if (check_diff(N, M, X, Y, mid)) ok = true;
        else if (check_diff(M, N, Y, X, mid)) ok = true;
        
        if (ok) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}