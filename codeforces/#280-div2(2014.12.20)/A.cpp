#include<stdio.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i*(i+1)*(i+2)/6<=n;i++);
	printf("%d\n",i-1);
 return 0;
}

