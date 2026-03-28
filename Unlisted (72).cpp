#include<stdio.h>
int main()
{
char name[20],dob[20],add[20],gen;
int id;
printf("enter studentname,dob,add,gen,id");
scanf("%s%s%%s %c%d",&name,&dob,&add,&gen,&id);
printf("studentname=%s\ndob=%s\nadd=%s\ngen=%c\nid=%d",name,dob,add,gen,id);
return 0;
}
