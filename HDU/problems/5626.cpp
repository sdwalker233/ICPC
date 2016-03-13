#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
using namespace std;
long long seed;
int n;
int x[MAXN],y[MAXN],a;

inline long long rand(long long l, long long r)
{
	static long long mo=1e9+7, g=78125;
	return l+((seed*=g)%=mo)%(r-l+1);
}

void fuck()
{
	int i,l,r;
	scanf("%d%lld",&n,&seed);
	for(i=1;i<=n;i++){
		x[i]=rand(-1000000000,1000000000);
		y[i]=rand(-1000000000,1000000000);
	}
	l=0x7fffffff;r=-0x80000000;
	for(i=1;i<=n;i++){
		a=x[i]+y[i];
		l=min(l,a);
		r=max(r,a);
	}
	int ans=r-l;
	l=0x7fffffff;r=-0x80000000;
	for(i=1;i<=n;i++){
		a=x[i]-y[i];
		l=min(l,a);
		r=max(r,a);
	}
	ans=max(ans,r-l);
	printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}