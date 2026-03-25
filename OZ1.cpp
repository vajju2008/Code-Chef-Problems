#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;
        
        int balance = 0;
        int count = 0;
        
        for (char c : S) {
            if (c == '1') balance++;
            else balance--;
            
            if (balance >= 0) {
                count++;
            }
        }
        
        cout << count << "\n";
    }
    return 0;
}