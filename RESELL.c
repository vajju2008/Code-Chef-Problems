#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);
        int A[100];
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        qsort(A, N, sizeof(int), compare);

        int total_profit = 0;
        for (int i = 0; i < N; i++) {
            int cost = (i < K) ? 5 : 10;
            if (A[i] - cost > 0) {
                total_profit += (A[i] - cost);
            }
        }
        printf("%d\n", total_profit);
    }
    return 0;
}