#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#define MAXN 100010
using namespace std;
int n;
long long c;
long long v[MAXN];
int x[MAXN],d[MAXN];

void fuck()
{
	int i,q;
	long long k,t;
	scanf("%d%lld",&n,&c);
	for(i=1;i<=n;i++)
		scanf("%lld%d%d",&v[i],&x[i],&d[i]);
	scanf("%d",&q);
	sort(v+1,v+n+1);
	while(q-->0){
		scanf("%lld%lld",&t,&k);
		double ans=sqrt(2.0*t*c+v[k]*v[k]);
		printf("%.3f\n",ans);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

