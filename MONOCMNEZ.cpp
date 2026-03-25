#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool checkCase1(ll K, int N, int M, const vector<ll>& X, const vector<ll>& Y) {
    ll xN = X[N - 1];
    ll yM = Y[M - 1];

    ll limitX = xN - (K / yM);
    ll limitY = yM - (K / xN);

    int p = lower_bound(X.begin(), X.end(), limitX) - X.begin();
    int q = lower_bound(Y.begin(), Y.end(), limitY) - Y.begin();

    int start_i = max(0, p - 1);
    int start_j = max(0, q - 1);

    ll mbY_max = Y[start_j];
    ll mbY_min = (q > 0) ? Y[0] : Y[start_j]; 

    for (int i = start_i; i < N - 1; ++i) {
        ll mbX_max = X[i];
        ll mbX_min = (p > 0) ? X[0] : X[i];

        if ((mbX_max - mbX_min) * mbY_max > K) continue;
        if ((mbY_max - mbY_min) * mbX_max > K) continue;

        return true;
    }

    return false;
}

bool checkCase3(ll K, int N, int M, const vector<ll>& X, const vector<ll>& Y) {
    ll xN = X[N - 1];
    ll yM = Y[M - 1];

    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < M - 1; ++j) {
            ll xi = X[i];
            ll yj = Y[j];

            ll R_lim_X = xN - (K / yj); 
            ll B_lim_X = xi - (K / yM); 
            ll R_lim_Y = yj - (K / xN); 
            ll B_lim_Y = yM - (K / xi); 

            if (X[i+1] < R_lim_X) continue;

            if (X[0] < R_lim_X) {
                if (X[0] < B_lim_X) continue;
            } else {
                if (xi < B_lim_X) continue;
            }

            if (Y[j+1] < B_lim_Y) continue;

            if (yj < R_lim_Y) continue;
            
            ll min_BY;
            if (Y[0] < R_lim_Y) min_BY = Y[0]; 
            else min_BY = Y[j+1]; 
            
            if (min_BY < B_lim_Y) continue;

            return true;
        }
    }
    return false;
}

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    
    vector<ll> X(N), Y(M);
    for (int i = 0; i < N; ++i) cin >> X[i];
    for (int i = 0; i < M; ++i) cin >> Y[i];
    
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    ll low = 0, high = 2000000000000000000LL; 
    ll ans = high;

    for(int iter=0; iter<65; ++iter) {
        if (low > high) break;
        ll mid = low + (high - low) / 2;
        
        bool possible = false;
        
        if (checkCase1(mid, N, M, X, Y)) possible = true;
        if (!possible && checkCase3(mid, N, M, X, Y)) possible = true;
        if (!possible && checkCase3(mid, M, N, Y, X)) possible = true;

        if (possible) {
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
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}