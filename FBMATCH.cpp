#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        string S;
        cin >> S;

        vector<int> freq(26, 0);

        for (char c : S) {
            freq[c - 'a']++;
        }

        bool possible = false;
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= 2) {
                possible = true;
                break;
            }
        }

        if (possible)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
