#include <stdio.h>

int main() {
    int num1 = 15;
    int num2 = 30;
    int sum;
    int *ptr1, *ptr2;

    ptr1 = &num1;
    ptr2 = &num2;

    sum = *ptr1 + *ptr2;

    printf("Sum = %d", sum);

    return 0;
}
