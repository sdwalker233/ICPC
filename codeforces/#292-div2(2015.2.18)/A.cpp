#include<stdio.h>

int main()
{
	int a,b,s;
	bool ok=0;
	scanf("%d%d%d",&a,&b,&s);
	if(a<0) a=0-a;
	if(b<0) b=0-b;
	if(a+b<=s&&(a+b)%2==s%2) printf("Yes\n");
	else printf("No\n");
 return 0;
}

