#include <stdio.h>
#include <stdlib.h> // Included for exit() and better practice

int PrisonTransfer(int N, int T, int C, int Arr[]) {
    int safe_ways = 0;
    int i, j;
    for (i = 0; i <= N - C; i++) {
        // Assume the current group is safe before checking its members
        int is_safe = 1; 
        
        for (j = 0; j < C; j++) {
            // Check the severity of the current prisoner in the group: Arr[i + j]
            if (Arr[i + j] > T) {
                // If any prisoner exceeds the threshold (T), the group is unsafe.
                is_safe = 0;
                break; // Exit the inner loop immediately 
            }
        }

        if (is_safe == 1) {
            safe_ways++; // Increment the count of safe transfer ways
        }
    }

    return safe_ways;
} // Closing brace for PrisonTransfer function

int main() {
    int N, T, C, ans;
    int i;
    
    printf("--- Prison Transfer Risk Analyzer ---\n\n");
    
    // --- Input Validation and Reading (N, T, C) ---
    
    printf("Enter the total number of prisoners (N): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Invalid input for N. N must be a positive integer. Exiting.\n");
        return 1;
    }

    printf("Enter the maximum safe crime severity threshold (T): ");
    if (scanf("%d", &T) != 1 || T < 0) {
        printf("Invalid input for T. T must be a non-negative integer. Exiting.\n");
        return 1;
    }

    printf("Enter the required size of the transfer group (C): ");
    if (scanf("%d", &C) != 1 || C <= 0 || C > N) {
        printf("Invalid input for C (must be > 0 and <= N). Exiting.\n");
        return 1;
    }

    int Arr[N]; 

    printf("\nEnter the crime severity score for each of the %d prisoners:\n", N);
    for (i = 0; i < N; i++) {
        printf("Prisoner %d Severity: ", i + 1);
        if (scanf("%d", &Arr[i]) != 1 || Arr[i] < 0) {
            printf("Invalid severity input. Severity must be non-negative. Exiting.\n");
            return 1;
        }
    }
    ans = PrisonTransfer(N, T, C, Arr);

    printf("\n-------------------------------------------------\n");
    printf("Transfer Constraints Summary:\n");
    printf("  Group Size (C): %d\n", C);
    printf("  Max Safe Severity (T): %d\n", T);
    printf("-------------------------------------------------\n");
    printf("The number of safe, contiguous ways to choose the %d prisoners is: %d\n", C, ans);
    printf("-------------------------------------------------\n");

    return 0;
} 
