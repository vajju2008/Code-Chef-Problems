#include <iostream>


#include <vector>

using namespace std;



using ll = long long;

using i128 = __int128_t;



static const ll MODV = 998244353;




int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);




    int tests;

    cin >> tests;

    while (tests--) {
        int n;
        cin >> n;

        vector<ll> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];

        vector<ll> stkVal, stkCnt, accCnt;
        vector<i128> accSum;

        ll prevSum = 0;
        i128 answer = 0;

        for (int r = 1; r <= n; r++) {
            ll add = arr[r] > 0 ? arr[r] : 1;
            ll curSum = prevSum + add;

            ll base = -prevSum + (arr[r] - 1 < 0 ? arr[r] - 1 : 0);
            ll freq = 1;

            while (!stkVal.empty() && stkVal.back() < base) {
                freq += stkCnt.back();
                stkVal.pop_back();
                stkCnt.pop_back();
                accCnt.pop_back();
                accSum.pop_back();
            }

            stkVal.push_back(base);
            stkCnt.push_back(freq);

            if (accCnt.empty()) {
                accCnt.push_back(freq);
                accSum.push_back((i128)freq * base);
            } else {
                accCnt.push_back(accCnt.back() + freq);
                accSum.push_back(accSum.back() + (i128)freq * base);
            }

            ll limit = -curSum;
            int lo = 0, hi = (int)stkVal.size() - 1, pos = -1;

            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (stkVal[mid] > limit) {
                    pos = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            if (pos >= 0) {
                answer += (i128)accCnt[pos] * curSum + accSum[pos];
            }

            prevSum = curSum;
        }

        ll res = (ll)(answer % MODV);
        if (res < 0) res += MODV;
        cout << res << '\n';
    }

    return 0;
}
