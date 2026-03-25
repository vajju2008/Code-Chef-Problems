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

        int A = 0, B = 0;
        char server = 'A'; // Alice starts

        for (char c : S) {
            if (c == server) {
                // server wins ? score++
                if (server == 'A') A++;
                else B++;
            } else {
                // receiver wins ? becomes new server
                server = c;
            }
        }

        cout << A << " " << B << "\n";
    }
    return 0;
}

