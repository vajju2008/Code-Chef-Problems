#include <stdio.h>


int fibonacci(int n) {
    
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    
    printf("Enter the value of n: ");
    scanf("%d", &n);

    
    printf("Fibonacci Series up to %d terms: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}