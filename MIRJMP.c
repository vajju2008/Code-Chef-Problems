#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A simple structure to hold a state (position and moves to change thw position) 
typedef struct {
    int position;
    int moves;
} State;

// A basic queue implementation using an array to get results  
State queue[200];
int front = -1, rear = -1;

void enqueue(State s) {
    if (rear == 199) return;
    if (front == -1) front = 0;
    queue[++rear] = s;
}

State dequeue() {
    return queue[front++];
}

bool is_empty() {
    return front > rear;
}

// Function to find the minimum moves 
int min_moves(int N, int K) {
    if (K == N) {
        return 0;
    }

    bool visited[N + 1];
    for (int i = 1; i <= N; ++i) {
        visited[i] = false;
    }

    front = 0;
    rear = -1;
    
    State initial_state = {K, 0};
    enqueue(initial_state);
    visited[K] = true;

    while (!is_empty()) {
        State current = dequeue();

        // Check for the target point
        if (current.position == N) {
            return current.moves;
        }

        // Possible moves
        int next_pos_left = current.position - 1;
        int next_pos_right = current.position + 1;
        int next_pos_mirror = N + 1 - current.position;

        // Move left
        if (next_pos_left >= 1 && !visited[next_pos_left]) {
            State next_state = {next_pos_left, current.moves + 1};
            enqueue(next_state);
            visited[next_pos_left] = true;
        }

        // Move right
        if (next_pos_right <= N && !visited[next_pos_right]) {
            State next_state = {next_pos_right, current.moves + 1};
            enqueue(next_state);
            visited[next_pos_right] = true;
        }

        // Mirror jump
        if (next_pos_mirror >= 1 && next_pos_mirror <= N && !visited[next_pos_mirror]) {
            State next_state = {next_pos_mirror, current.moves + 1};
            enqueue(next_state);
            visited[next_pos_mirror] = true;
        }
    }

    return -1; // Should not be reached given the problem constraints
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);
        printf("%d\n", min_moves(N, K));
    }
    return 0;
}