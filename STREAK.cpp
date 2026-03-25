#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int max_streak = 0;
    int current_streak = 0;
    
    for (int i = 0; i < N; i++) {
        if (A[i] > 0) {
            current_streak++;
            max_streak = max(max_streak, current_streak);
        } else {
            current_streak = 0;
        }
    }
    
    cout << max_streak << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}