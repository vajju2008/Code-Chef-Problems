#include <stdio.h>
#include <stdlib.h>

struct student 
{
	int sno;
	char name[50];
	char sex;
	float marks;
};

typedef struct student student;

int main()
{
	student *ps;
	ps = (student*)malloc(sizeof(student));
	
	printf ("Enter student data \n");
 scanf	("%d %s %c %f", &ps->sno, &ps->name, &ps->sex, &ps->marks);
 
 printf ("The student data:");
 printf ("%d %s %c %f", &ps->sno,&ps->name, &ps->sex, &ps->marks);
}
	