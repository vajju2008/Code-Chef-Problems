#include <stdio.h>
#include <string.h>

#define MAX_HOTELS 5  
struct Hotel {
    char name[50];
    char address[100];
    float rating;
    float room_charge;
    int number_of_rooms;
}
struct Hotel hotel_stack[MAX_HOTELS];
int top = -1; 
int isFull() {
    return top == MAX_HOTELS - 1;
}
int isEmpty() {
    return top == -1;
}
void push(struct Hotel hotel) {
    if (isFull()) {
        printf("Stack overflow! Cannot add more hotels.\n");
        return;
    }
    hotel_stack[++top] = hotel;
}
struct Hotel pop() {
    if (isEmpty()) {
        printf("Stack underflow! No hotels to remove.\n");
        struct Hotel empty_hotel = {"", "", 0, 0, 0};
        return empty_hotel;
    }
    return hotel_stack[top--];
}
void printHotelDetails(struct Hotel hotel) {
    printf("Hotel Name: %s\n", hotel.name);
    printf("Address: %s\n", hotel.address);
    printf("Rating: %.2f\n", hotel.rating);
    printf("Room Charge: %.2f\n", hotel.room_charge);
    printf("Number of Rooms: %d\n", hotel.number_of_rooms);
    printf("------------------------------------------\n");
}
void printAllHotelDetails() {
    if (isEmpty()) {
        printf("No hotels in the stack.\n");
        return;
    }
    
    printf("Total Hotels in Stack: %d\n", top + 1);
    for (int i = 0; i <= top; i++) {
        printHotelDetails(hotel_stack[i]);
    }
}

int main() {
    struct Hotel hotel1 
    struct Hotel hotel2 
    struct Hotel hotel3 
    push(hotel1);
    push(hotel2);
    push(hotel3);
    printAllHotelDetails();
 
    printf("Popping one hotel from stack:\n");
    struct Hotel popped_hotel = pop();
    printHotelDetails(popped_hotel);
    
    printf("Remaining hotels in stack after pop:\n");
    printAllHotelDetails();
    
    return 0;
}
