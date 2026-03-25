#include <stdio.h>

int main() {
    int num1, num2;

    // Prompt the user to enter two numbers
    printf("Enter two numbers to swap: ");

    // Read the two numbers from the user
    scanf("%d %d", &num1, &num2);

    // Display the numbers before swapping
    printf("Before swapping:\n");
    printf("First number: %d\n", num1);
    printf("Second number: %d\n", num2);

    // Swap the numbers using the XOR bitwise operator
    num1 = num1 ^ num2;  // Step 1: num1 now holds the XOR of original num1 and num2
    num2 = num1 ^ num2;  // Step 2: num2 now becomes the original num1
    num1 = num1 ^ num2;  // Step 3: num1 now becomes the original num2

    // Display the numbers after swapping
    printf("\nAfter swapping:\n");
    printf("First number: %d\n", num1);
    printf("Second number: %d\n", num2);

    return 0;
}
