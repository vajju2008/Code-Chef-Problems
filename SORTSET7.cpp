#include <bits/stdc++.h>
using namespace std;

static const long long MODV = 998244353;

static const int LIM = 200005;

long long f[LIM], finv[LIM], invv[LIM];

void init() {
    f[0] = finv[0] = 1;
    
    invv[1] = 1;

    for (int i = 2; i < LIM; i++)
        invv[i] = MODV - (MODV / i) * invv[MODV % i] % MODV;
    for (int i = 1; i < LIM; i++) {
        f[i] = f[i - 1] * i % MODV;
        finv[i] = finv[i - 1] * invv[i] % MODV;

    }
}

inline long long C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return f[n] * finv[r] % MODV * finv[n - r] % MODV;
}

inline long long prefSum(int n, int r) {
    if (r > n) return 0;

    long long a = (r + 1) * C(n + 2, r + 2) % MODV;
    long long b = C(n + 1, r + 1);
    return (a - b + MODV) % MODV;
}

void compute() {

    int n;
    long long k;
    cin >> n >> k;

    long long ans = 0;
    long long base = (1LL * n * (n + 1) / 2) % MODV;
    long long common = base * f[n - 1] % MODV;

    for (int len = 2; len <= n; len++) {
        ans = (ans + common) % MODV;


        long long limit;

        if (len == 2) limit = n;

        else limit = (len + k) / (len - 2);


        long long maxCnt = n - len + 1;

        if (limit > maxCnt) limit = maxCnt;


        long long permWays = f[len - 1] * f[n - len] % MODV;

        long long chooseSum = 0;


        if (limit > 0)
            chooseSum = (C(n, len) - C(n - limit, len) + MODV) % MODV;

        long long weightedSum = 0;
        if (limit > 0) {
            long long full = prefSum(n - 1, len - 1);
            long long low = prefSum(n - limit - 1, len - 1);
            long long diff = (full - low + MODV) % MODV;
            weightedSum = (n * chooseSum % MODV - diff + MODV) % MODV;
        }

        long long part1 = (len - 2) * weightedSum % MODV;
        long long part2 = (len - 1) * (k % MODV) % MODV * chooseSum % MODV;
        long long directCost = (part1 + part2) % MODV;

        long long totalComb = C(n, len);
        long long rest = (totalComb - chooseSum + MODV) % MODV;
        long long borrowCost = rest * (len * ((k + 1) % MODV) % MODV) % MODV;

        long long finalAdd = (directCost + borrowCost) % MODV;
        ans = (ans + finalAdd * permWays) % MODV;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    int t;
    cin >> t;
    while (t--) compute();
    return 0;
}
