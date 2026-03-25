#include <stdio.h>
struct Hotel {
    char name[50];
    char address[100];
    float rating;
    float room_charge;
    int number_of_rooms;
};rintHotelDetails(struct Hotel h) {

void pintf("Hotel Name: %s\n", h.name);
    printf("Hotel Address: %s\n", h.address);
    printf("Hotel Rating: %.1f\n", h.rating);
    printf("Room Charge: %.2f\n", h.room_charge);
    printf("Number of Rooms: %d\n", h.number_of_rooms);
}
int main() {
    struct Hotel h;
    printf("Enter the hotel name: ");
    fgets(h.name, sizeof(h.name), stdin);
    printf("Enter the hotel address: ");
    fgets(h.address, sizeof(h.address), stdin);
    printf("Enter the hotel rating: ");
    scanf("%f", &h.rating);
    printf("Enter the room charge: ");
    scanf("%f", &h.room_charge);
    printf("Enter the number of rooms: ");
    scanf("%d", &h.number_of_rooms);
    printf("\nHotel Details:\n");
    printHotelDetails(h);

    return 0;
}
