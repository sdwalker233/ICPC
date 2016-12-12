#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int n,m,a[MAXN],d[MAXN],b[MAXN];
bool vis[MAXN];

bool check(int x)
{
	int i;
	memset(vis,0,sizeof(vis));
	memcpy(d,b,sizeof(d));
	for(i=x;i>=1;i--){
		if(d[i]==0) continue;
		if(vis[d[i]]==0) vis[d[i]]=1;
		else d[i]=0;
	}
	for(i=1;i<=m;i++)
		if(vis[i]==0) return 0;
	int p=0;
	for(i=1;i<=x;i++){
		if(d[i]==0) p++;
		else p-=a[d[i]];
		if(p<0) return 0;
	}
	return 1;
}

int main()
{
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	for(i=1;i<=m;i++) scanf("%d",&a[i]);
	int l=1,r=n,mid,ans=n+1;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=min(ans,mid);
			r=mid-1;
		}
		else l=mid+1;
	}
	if(ans==n+1) ans=-1;
	printf("%d\n",ans);
 return 0;
}

