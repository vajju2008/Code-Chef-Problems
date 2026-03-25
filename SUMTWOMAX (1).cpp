#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;
    
    vector<int> pos(N + 1);
    for (int i = 1; i <= N; ++i) {
        int val;
        cin >> val;
        pos[val] = i;
    }

    vector<int> L(N + 2), R(N + 2);
    for (int i = 1; i <= N; ++i) {
        L[i] = i - 1;
        R[i] = i + 1;
    }
    
    R[0] = 1; 
    L[N + 1] = N;

    long long total_sum = 0;

    for (int v = 1; v <= N; ++v) {
        int idx = pos[v];

        int L1 = L[idx];
        int L2 = (L1 >= 1) ? L[L1] : 0; 
        
        int R1 = R[idx];
        int R2 = (R1 <= N) ? R[R1] : N + 1;

        long long left_greater = 0;
        if (L1 >= 1) {
            long long effective_L2 = max(0, L2);
            left_greater = 1LL * (L1 - effective_L2) * (R1 - idx);
        }

        long long right_greater = 0;
        if (R1 <= N) {
            long long effective_R2 = min(N + 1, R2);
            right_greater = 1LL * (idx - L1) * (effective_R2 - R1);
        }

        total_sum += 1LL * v * (left_greater + right_greater);

        int left_neighbor = L[idx];
        int right_neighbor = R[idx];
        
        R[left_neighbor] = right_neighbor;
        L[right_neighbor] = left_neighbor;
    }

    cout << total_sum << "\n";
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