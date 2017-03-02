#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
int n;
int c[MAXN],d[MAXN];

int main()
{
	int i;
	int L=-200000001,R=200000001;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&c[i],&d[i]);
	}
	if(d[1]==1) L=1900;
	else R=1899;
	for(i=1;i<n;i++){
		L+=c[i];R+=c[i];
		if(d[i+1]==1) L=max(L,1900);
		else R=min(R,1899);
		//printf(" %d %d\n",L,R);
		if(L>R) break;
	}
	L+=c[n];R+=c[n];
	if(i<n) printf("Impossible\n");
	else if(R>=100000001) printf("Infinity\n");
	else printf("%d\n",R);
 return 0;
}

