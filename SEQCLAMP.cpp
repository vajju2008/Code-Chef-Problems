//  The clamp function is monotonically non-decreasing. This means if you start with two values a1 n 2  where1 / 2 , applying the clampoperation to both will result in . Because the relative ordering never dropmaximizing your initial starting value  guarantees the absolute maximum possible final value after all N steps

#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 1000; 
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ans = max(a, min(ans, b));
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}