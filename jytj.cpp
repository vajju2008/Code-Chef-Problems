 #include<stdio.h>
 int main(){
 	int i,j,n,c=1,t;
 	printf("enter n value");
 	scanf("%d",&n);
 	while(t--){
 	for(i=0;i<=n;i++){
 		for(j=0;j<=i;j++){
 			if(i==j){
 				printf("%d",c);
				}
				else{
					printf("%d",c);
				}
				printf("%d*",c);
				printf("\n");
			}
		}
		c++;
	}
}