#include<stdio.h>
struct Hotel
{
	char name[100];
	char address[200];
	float rating;
	float room_change;
	int number_of_room;
};
void printfHotelDetails(struct Hotel h)
{
	printf("hotel name : %s",h.name);
	printf("address : %s",h.address);
	printf("rating : 2f\n",h.rating);
	printf("room change : $%2f per night\n",h.room_change);
	printf("number of rooms : %d\n",h.number_of_room);
}
int main ()
{
	struct Hotel myHotel;
	printf("enter hotel name :");
	fgets(myHotel.name,sizeof(myHotel.name),stdin);
	printf("enter hotel address :");
	fgets(myHotel.address,sizeof(myHotel.address),stdin);
	printf("enter room rating (out of 5): ");
	scanf("%f",&myHotel.rating);
	printf("enter room change (per night) :");
	scanf("%f",&myHotel.room_change);
	printf("enter nuber of rooms : ");
	scanf("%f",&myHotel.number_of_room);
	printf(" Hotel details(myHotel)");
	return 0;	
}