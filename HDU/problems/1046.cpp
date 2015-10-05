#include<stdio.h>

int main()
{
	int n,i,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		printf("Scenario #%d:\n%d.",i,a*b);
		if(a%2&&b%2) printf("41\n\n");
		else printf("00\n\n");
	}
 return 0;
}

