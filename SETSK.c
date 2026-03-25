#include <stdio.h>
#include <stdbool.h>

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);
        int B[101];
        bool has_one = false;
        for (int i = 1; i <= N; i++) {
            scanf("%d", &B[i]);
            if (B[i] == 1) has_one = true;
        }

        if (!has_one) {
            printf("No\n");
            continue;
        }

        bool possible = true;
        for (int i = 1; i <= N; i++) {
            if (B[i] == 1) {
                for (int j = i + 1; j <= i + K && j <= N; j++) {
                    if (B[j] == 1) {
                        possible = false;
                        break;
                    }
                }
            } else {
                bool covered = false;
                for (int j = i - K; j <= i + K; j++) {
                    if (j >= 1 && j <= N && B[j] == 1) {
                        covered = true;
                        break;
                    }
                }
                if (!covered) possible = false;
            }
            if (!possible) break;
        }

        printf(possible ? "Yes\n" : "No\n");
    }
    return 0;
}