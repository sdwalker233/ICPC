#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define INF 0x7fffffff
using namespace std;

int main()
{
	int i,n,r1=0,r2,p1=0,p2=INF,a,b,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		r1=max(r1,x);
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		p1=max(p1,x);
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		p2=min(p2,x);
	}
	scanf("%d%d",&a,&b);
	printf("%lf",sqrt((double)b*r1*r1*p1/(b*p1+a*p2)));
 return 0;
}

