#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000


typedef struct {
    int *data;
    int size;
    int capacity;
} IntList;


void initList(IntList *list) {
    list->size = 0;
    list->capacity = 1; // Start with a small capacity
    list->data = (int *)malloc(list->capacity * sizeof(int));
    if (list->data == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
}


void addToList(IntList *list, int val) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
        if (list->data == NULL) {
            perror("Failed to reallocate memory");
            exit(EXIT_FAILURE);
        }
    }
    list->data[list->size++] = val;
}

// Function to free the memory used by the list
void freeList(IntList *list) {
    if (list->data != NULL) {
        free(list->data);
        list->data = NULL;
    }
    list->size = 0;
    list->capacity = 0;
}

// Function to compute the Greatest Common Divisor (GCD) using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve() {
    int N;
    if (scanf("%d", &N) != 1) return;

    // Use an array of IntList to group players by their score (gcd).
    // The maximum possible score is N. We use a size of N+1 for 1-based indexing.
    IntList score_groups[MAX_N + 1];
    
    // Initialize all lists
    for (int i = 1; i <= N; ++i) {
        initList(&score_groups[i]);
    }

    // Step 1 & 2: Calculate scores and group players
    for (int i = 1; i <= N; ++i) {
        int player_score = gcd(i, N);
        // The player number 'i' is added to the list corresponding to the score.
        // Since we iterate 'i' from 1 to N, the players within each list 
        // are automatically stored in ASCENDING order of player number, 
        // satisfying the secondary sort condition.
        addToList(&score_groups[player_score], i);
    }

    // Step 3 & 4: Output the players in the required order
    // Primary sort key (score) must be in DESCENDING order.
    // We iterate the score (index) from N down to 1.
    int first_output = 1; // Flag to manage spaces between numbers
    for (int score = N; score >= 1; --score) {
        IntList *current_list = &score_groups[score];
        
        // Only print if there are players with this score (i.e., 'score' is a divisor of N)
        if (current_list->size > 0) {
            // Print all players in this group (already sorted by player number)
            for (int i = 0; i < current_list->size; ++i) {
                if (!first_output) {
                    printf(" ");
                }
                printf("%d", current_list->data[i]);
                first_output = 0;
            }
        }
        // Free memory for this list after use
        freeList(current_list);
    }

    printf("\n");
}

int main() {
    int T;
    // Read the number of test cases
    if (scanf("%d", &T) != 1) {
        return 1;
    }

    // Ensure MAX_N is large enough for the constraints
    if (MAX_N < 100) { // A basic check, adapt as needed
        fprintf(stderr, "Warning: MAX_N may be too small for larger test cases.\n");
    }

    // Loop through all test cases
    while (T--) {
        solve();
    }
    
    return 0; //n players 
}