#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
int n,k,s,t;
long long d[MAXN];
int v[MAXN],c[MAXN],b[MAXN],g[MAXN];

bool check(int x)
{
	int i;
	long long tt=0;
	for(i=1;i<=k+1;i++){
		if(x<d[i]) return 0;
		if(x>=2*d[i]) tt+=d[i];
		else tt+=3*d[i]-x;
	}
	if(tt<=t) return 1;
	return 0;
}

int main()
{
	int i;
	scanf("%d%d%d%d",&n,&k,&s,&t);
	for(i=1;i<=n;i++){
		scanf("%d%d",&c[i],&v[i]);
	}
	for(i=1;i<=k;i++){
		scanf("%d",&g[i]);
	}
	sort(g+1,g+k+1);
	g[0]=0;g[k+1]=s;
	for(i=1;i<=k+1;i++){
		d[i]=g[i]-g[i-1];
	}
	int l=1,r=1e9+1,mn=1e9+1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			mn=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	//printf(" %d\n",mn);
	int ans=1e9+1;
	for(i=1;i<=n;i++){
		if(v[i]>=mn&&c[i]<ans) ans=c[i];
	}
	if(ans>1e9) ans=-1;
	printf("%d\n",ans);
 return 0;
}

