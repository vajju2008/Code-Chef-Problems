#include <stdio.h>
#include <math.h>
int main ()
{
	char tcA[50], tcB[50];
	int x1, x2, y1, y2;
	printf ("Enter Treature coordinates of A (x1,y1):");
	scanf ("%s", &tcA[50]);
	x1 = tcA[1];
	y1 = tcA[3];
	printf ("Enter Treasure coordinates of B (x2,y2):");
	scanf ("%s", &tcB[50]);
	x2 = tcB[1];
	y2 = tcB[3];
	int distance;
	distance = sqrt((x2-x1)^2 + (y2-y1)^2);
	printf ("Distance between Treasures is: %d", distance);
	return 0;
}