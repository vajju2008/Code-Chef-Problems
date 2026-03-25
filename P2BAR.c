#include <stdio.h>
#include <string.h>
#define MAX_N 15

void solve() {
    int N;
    char S[MAX_N];
    int first_zero_index = -1;
    int pulse_count = 0;
    

    if (scanf("%d", &N) != 1) return;
    if (scanf("%s", S) != 1) return;

    for (int i = 0; i < N; i++) {
        if (S[i] == '0') {
            first_zero_index = i;
            break; 
        }
    }

    if (first_zero_index != -1) {
      
        for (int i = first_zero_index + 1; i < N; i++) {
            if (S[i] == '1') {
                pulse_count++;
            }
        }
    }
    
    printf("%d\n", pulse_count);
}
int main() {
    int T;
    
    if (scanf("%d", &T) != 1) return 1;
    
    while (T--) {
        solve();
    }
    
    return 0;
}