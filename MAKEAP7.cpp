#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // on flase to sync 
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<long long> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        long long d = 0;
        for (int i = 1; i < N; i++) {
            d = gcd(d, A[i] - A[i - 1]);
        }

        long long ops = 0;
        for (int i = 1; i < N; i++) {
            ops += (A[i] - A[i - 1]) / d - 1;
        }

        cout << ops << "\n";
    }

    return 0;
}
