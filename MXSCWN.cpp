#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N; // opponents 
    
    cin >> N; // opponents always greater than b 
    
    vector<int> A(N);
    vector<int> B(N);
    
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    
    int total_score = 0;
    
    int min_diff = 1000000;
    
    for (int i = 0; i < N; i++) {
        total_score += A[i];
        if ((A[i] - B[i]) < min_diff) {
            min_diff = A[i] - B[i];
        }
    }
    
    cout << total_score - min_diff << endl;
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