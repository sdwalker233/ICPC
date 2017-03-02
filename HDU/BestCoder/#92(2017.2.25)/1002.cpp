#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;
int n,m,k;
int x[MAXN],y[MAXN],cx[MAXN],cy[MAXN];

void fuck()
{
	int i;
	memset(cx,0,sizeof(cx));
	memset(cy,0,sizeof(cy));
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=k;i++){
		scanf("%d%d",&x[i],&y[i]);
		cx[x[i]]++;cy[y[i]]++;
	}
	long long sum=0;
	for(i=1;i<=k;i++){
		sum+=1ll*(cx[x[i]]-1)*(cy[y[i]]-1);
	}
	printf("%lld\n",sum*2);
}

int main()
{
	int i,t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

