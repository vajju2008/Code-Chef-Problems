#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios::sync_with_stdio(false); // flase becaue....
    cin.tie(nullptr);
    
    
    int t;
    if (!(cin >> t)) return 0;   // read  test cases of the bnumbers
    
    
    while (t--) {
        
        long long n;
        cin >> n;                // read length of the std::array<T, N> ;
        
        
       
        
        // But to avoid overflow and keep it neat, /a clean 
        // we split it into two  differenet parts parts
       
        
        long long a = (n - 1) / 2;
        long long b = (n - 2) / 2;
        
        cout << a * b << "\n";
    }
    
    
    return 0;
}
