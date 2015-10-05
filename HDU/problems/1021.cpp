#include<stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		n%=8;
		if(n==2||n==6) printf("yes\n");
		else printf("no\n");
	}
 return 0;
}

