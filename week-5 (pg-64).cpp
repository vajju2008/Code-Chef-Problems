# include<stdio.h>
int main()
{
	int n,m;
	printf("Enter value of n");
	scanf("%d",&n);
	printf("Enter value of m");
	scanf("%d",&m);
	printf("n left shift 5times:%d\n",n<<5);
	printf("m right shift 2times:%d\n",m>>2);
	return 0;
}