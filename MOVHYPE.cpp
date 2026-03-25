#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; //upto 2n+1 
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N + 1); 
        for (int i = 0; i <= N; i++) { // for loop greter or = to n 
            cin >> A[i];
        }

        int ans = INT_MAX;

        for (int i = 0; i < N; i++) {
            ans = min(ans, max(A[i], A[i + 1]));
        }

        cout << ans << "\n";
    }

    return 0;
}
