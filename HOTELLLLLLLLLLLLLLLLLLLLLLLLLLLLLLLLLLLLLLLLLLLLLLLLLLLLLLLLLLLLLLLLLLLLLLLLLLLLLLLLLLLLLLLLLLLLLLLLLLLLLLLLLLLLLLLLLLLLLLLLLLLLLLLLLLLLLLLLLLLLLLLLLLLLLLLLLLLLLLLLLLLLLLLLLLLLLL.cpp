#include <stdio.h>
#include <stdlib.h>

struct Hotel {
    char name[50];
    char address[100];
    float rating;
    float charge;
    int no_of_rooms;
};

typedef struct Hotel Hotel;

int main() {
    Hotel *hotel = (Hotel*)malloc(sizeof(Hotel));
    
    if (hotel == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter hotel details:\n");
    printf("Name: ");
    scanf(" %[^\n]%*c", hotel->name);  // Read string with spaces
    printf("Address: ");
    scanf(" %[^\n]%*c", hotel->address); // Read string with spaces
    printf("Rating (out of 5): ");
    scanf("%f", &hotel->rating);
    printf("Charge per night: ");
    scanf("%f", &hotel->charge);
    printf("Number of rooms: ");
    scanf("%d", &hotel->no_of_rooms);
    
    printf("\nHotel Details:\n");
    printf("Name: %s\n", hotel->name);
    printf("Address: %s\n", hotel->address);
    printf("Rating: %.1f\n", hotel->rating);
    printf("Charge per night: %.2f\n", hotel->charge);
    printf("Number of rooms: %d\n", hotel->no_of_rooms);
    
    free(hotel); // Free the allocated memory
    return 0;
}
