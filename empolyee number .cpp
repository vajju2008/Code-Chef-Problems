#include <stdio.h> // This library is needed for input and output functions like printf

int main() {
    // Declare and initialize a character array to store the name.
    // The value is now "hardcoded" directly into the program.
    char name[50] = "Sai Vatsal";

    // Declare and initialize a character array to store the mobile number.
    char mobileNumber[15] = "8341502007";

    // The program no longer needs to ask for input since the values are set.

    // Print a separator for better formatting
    printf("\n----------------------------------------\n");

    // Display the hardcoded information
    printf("Hello, %s!\n", name);
    printf("Your mobile number is: %s\n", mobileNumber);
    
    printf("----------------------------------------\n");

    // Return 0 to indicate that the program ran successfully
    return 0;
}

