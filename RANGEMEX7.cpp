#include <bits/stdc++.h>

using namespace std;

int main() {
        
    ios::sync_with_stdio(false);
    
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, K;
        cin >> n >> K;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<int> used(n + 2, 0);
        int mark = 1;
        int best = 0, cnt = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == K) {
                best = max(best, cnt);
                cnt = 0;
                mark++;
            } else if (arr[i] < K) {
                if (used[arr[i]] != mark) {
                    used[arr[i]] = mark;
                    cnt++;
                }
            }
        }

        best = max(best, cnt);
        cout << (K - best + 1) << '\n';
    }

    return 0;
}
