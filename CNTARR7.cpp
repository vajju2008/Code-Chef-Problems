#include <iostream>
using namespace std;

static const long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; // opricamal max possible s
    cin >> tc;

    while (tc--) {
        long long n, m;
        cin >> n >> m;

        if (n == 1) {
            cout << (m + 1) % MOD << '\n';
            continue;
        }

        long long p = 1;
        while (p <= m) {
            p <<= 1;
        }

        long long xr = p - 1;
        long long ans = 2 * m - xr + 1;

        if (ans < 0) ans = 0;
        cout << ans % MOD << '\n';
    }

    return 0;
}
