#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, C;
        scanf("%d %d", &N, &C);

        int A[N]; // missions to play
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        char S[N+1];
        scanf("%s", S);

        int normal_sum = 0, special_sum = 0;

        // Separate sums
        for (int i = 0; i < N; i++) {
            if (S[i] == '0') {
                normal_sum += A[i];
            } else {
                special_sum += A[i];
            }
        }

        int coins = normal_sum;

        // Check if unlocking specials is beneficial
        if (normal_sum >= C && special_sum > C) {
            coins += (special_sum - C);
        }

        printf("%d\n", coins);
    }

    return 0;
}
