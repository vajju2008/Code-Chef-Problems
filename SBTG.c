#include <stdio.h>
#include <stdlib.h> // For qsort
#include <stdbool.h> // For boolean type

// Comparison function for qsort in descending order
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, X, K;
        scanf("%d %d %d", &N, &X, &K);
        int A[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        // Sort the opponent's scores in descending order
        qsort(A, N, sizeof(int), compare);
        
        int chef_score = X;
        int operations = K;
        
        // Sabotage the opponents with the highest scores first
        for (int i = 0; i < N && operations > 0; i++) {
            if (A[i] > chef_score) {
                // Perform sabotage operation
                A[i] = 0;
                chef_score += 100;
                operations--;
            }
        }
        
        // Recalculate rank based on the final scores
        int rank = 1;
        for (int i = 0; i < N; i++) {
            if (A[i] > chef_score) {
                rank++;
            }
        }
        
        printf("%d\n", rank);
    }
    return 0;
}