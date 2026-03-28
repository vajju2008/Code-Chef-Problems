#include<stdio.h>
#include<math.h>
int main()
{
	int l,i;
	char *ap,*gp,ch,str(100);
	printf ("enter a string");
	scanf("%s",&str);
	l=str,lem(str);
	ap=str;
	ep=str;
	for(i=0;i<l-1;i++)
	{
		gp++;
	}
    for(i=0;i<l/2;i++);
    {
    	ch+*gp;
    	*gp=*ap;
    	*ap=ch;
    	ap++;
    	gp--;
    }
    print("reverse of string:/n%s",str);
    return 0;
}
    	
	}
	
}
