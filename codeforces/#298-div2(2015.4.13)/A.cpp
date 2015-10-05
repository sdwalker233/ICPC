#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,i;
	scanf("%d",&n);
	if(n==1||n==2){printf("1\n1\n");return 0;}
	if(n==3){printf("2\n1 3\n");return 0;}
	if(n==4){printf("4\n2 4 1 3\n");return 0;}
	printf("%d\n",n);
	for(i=1;i<=n;i+=2)
		printf("%d ",i);
	for(i=2;i<=n-2;i+=2)
		printf("%d ",i);
	printf("%d\n",i);
 return 0;
}

