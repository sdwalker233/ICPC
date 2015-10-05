#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int v1,v2,t,d,i,tt,sum=0,a[110],b[110];
	scanf("%d%d%d%d",&v1,&v2,&t,&d);
	a[1]=v1;b[t]=v2;
	for(i=2;i<=t;i++)
		a[i]=a[i-1]+d;
	for(i=t-1;i>=1;i--)
		b[i]=b[i+1]+d;
	for(tt=1;tt<=t;tt++)
		if(a[tt]>b[tt]) break;
	for(i=1;i<tt;i++)
		sum+=a[i];
	for(i=tt;i<=t;i++)
		sum+=b[i];
	printf("%d\n",sum);
 return 0;
}

