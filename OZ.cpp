#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    string S;
    cin >> S;

    vector<int> p;
    p.reserve(N);
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            p.push_back(i + 1); 
        }
    }

    int K = p.size();
    
    if (K == 0) {
        cout << "0 0\n";
        return;
    }

    int max_f = min(N, 2 * K);
    vector<int> B(K);
    
    B[K - 1] = min(N, 2 * K - 1);

    for (int i = K - 2; i >= 0; --i) {
        B[i] = min(2 * (i + 1) - 1, B[i + 1] - 1);
    }

    long long min_swaps = 0;
    for (int i = 0; i < K; ++i) {
        if (p[i] > B[i]) {
            min_swaps += (long long)(p[i] - B[i]);
        }
    }

    cout << max_f << " " << min_swaps << "\n";
}

int main() {
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