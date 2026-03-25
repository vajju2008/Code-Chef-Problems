#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int MAX_N = 200005;

long long fact[MAX_N];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Psave time n run the test cases in time 
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int max_len = 0;
    int count_max = 0;
    int current_len = 1;

    if (n == 0) {
        cout << 0 << "\n";
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] == a[i] + 1) {
           
            current_len++;
        } else {
           
            if (current_len > max_len) {
                max_len = current_len;
                count_max = 1;
            } else if (current_len == max_len) {
                count_max++;
            }
            current_len = 1; 
        }
    }

    if (current_len > max_len) {
        max_len = current_len;
        count_max = 1;
    } else if (current_len == max_len) {
        count_max++;
    }

    long long term1 = count_max;
    long long term2 = power(2, max_len - 1);
    long long term3 = fact[n - max_len];

    long long ans = (term1 * term2) % MOD;
    ans = (ans * term3) % MOD;

    cout << ans << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}