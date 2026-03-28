#include<stdio.h>
void sun(char);
void fun(int);
int main() {
	char ssc = 12356;
	sun(ssc);
}
void sun(char s) {
	char f=s;
	printf("%d\n",f);
	char ss = 49;
fun(ss);
}
void fun(int s) {
	int ss=s;
	printf("%d",s);
}
