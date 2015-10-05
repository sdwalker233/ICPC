#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 200010
using namespace std;
int n,x[MAXN],y[MAXN];

void fuck()
{
	int i,x0,y0,n1=0,n2=0;
	for(i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	x0=x[n/2+1];y0=y[n/2+1];
	for(i=1;i<=n;i++){
		if(x[i]>x0&&y[i]>y0) n1++;
		else if(x[i]<x0&&y[i]<y0) n1++;
		else if(x[i]>x0&&y[i]<y0) n2++;
		else if(x[i]<x0&&y[i]>y0) n2++;
	}
	printf("%d %d\n",n1,n2);
}

int main()
{
	while(~scanf("%d",&n)&&n)
		fuck();
 return 0;
}


