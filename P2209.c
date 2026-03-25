#include <stdio.h>

void solve() {
    int X, Y;
    // Read the lower and upper bounds X and Y
    if (scanf("%d %d", &X, &Y) != 2) {
        return;
    }

    // N is the total count of multiples of X in the range [X, Y]
    // N = floor(Y / X)
    int N = Y / X;

    // Case 1: X is Even
    // If X is even, all multiples (k * X) are even. S_odd = 0. S_even > 0.
    // Result is YES.
    if (X % 2 == 0) {
        printf("YES\n");
    } 
    // Case 2: X is Odd
    else {
        // If X is odd, the parity of the multiple is the parity of the multiplier k.
        // Multiples are: Odd, Even, Odd, Even, ...
        
        // If the total count N is Even, there's an equal number of Odd/Even terms, 
        // but the Even terms are larger, so S_even > S_odd. Result is YES.
        if (N % 2 == 0) {
            printf("YES\n");
        } 
        // If the total count N is Odd, there's one more Odd term (the last one),
        // which makes S_odd larger than S_even. Result is NO.
        else {
            printf("NO\n");
        }
    }
}

int main() {
    int T;
    // Read the number of test cases
    if (scanf("%d", &T) != 1) {
        return 1;
    }
    
    // Loop through all test cases
    while (T--) {
        solve();
    }
    
    return 0;
}