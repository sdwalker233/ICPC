#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define MAXN 5010
using namespace std;
const int mod=1e9+7;
struct pp{
	int a,b;
	pp(int _a=0,int _b=0){
		a=_a;b=_b;
	}
	pp(const pp& x){
		a=x.a;b=x.b;
	}
}dp[MAXN][MAXN];
map<int,int> mp;
int n,m;
int a[MAXN],b[MAXN],pre[MAXN][MAXN],nxt[MAXN][MAXN],pos[MAXN];
 
inline void inc(int &x,int y){if((x+=y)>=mod)x-=mod;}
inline void dec(int &x,int y){if((x-=y)<0)x+=mod;}

void fuck()
{
	int i,j;
	mp.clear();
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	for(i=1;i<=m;i++) mp[b[i]]=i;
	for(i=1;i<=n;i++) a[i]=mp[a[i]];
	memset(pos,0,sizeof(pos));
	for(i=1;i<=n+1;i++){
		for(j=1;j<=m;j++) pre[i][j]=pos[j];
		pos[a[i]]=i;
	}
	memset(pos,0,sizeof(pos));
	for(i=n;i>=0;i--){
		for(j=1;j<=m;j++) nxt[i][j]=pos[j];
		pos[a[i]]=i;
	}
	for(i=n;i>=1;i--){
		dp[i][i]=pp(1,1);
		pp mx(0,1);
		for(j=i+1;j<=n;j++){
			if(a[j-1]<=a[i]){
				pp tmp=dp[nxt[i][a[j-1]]][pre[j-1][a[j-1]]];
				if(tmp.a==mx.a) dec(mx.b,tmp.b);
				tmp=dp[nxt[i][a[j-1]]][j-1];
				if(tmp.a>mx.a) mx=tmp;
				else if(tmp.a==mx.a) inc(mx.b,tmp.b);
			}
			dp[i][j]=a[j]==a[i]?pp(mx.a+2,mx.b):pp(0,0);
			//printf("  %d %d\n",mx.a,mx.b);
			//printf(" %d %d %d %d\n",i,j,dp[i][j].a,dp[i][j].b);
		}
	}
	pp ans(1,0);
	for(i=1;i<=n;i++){
		pp tmp=dp[nxt[0][i]][pre[n+1][i]];
		if(tmp.a>ans.a) ans=tmp;
		else if(tmp.a==ans.a) inc(ans.b,tmp.b);
	}
	printf("%d %d\n",ans.a,ans.b);
}

int main()
{
	while(~scanf("%d",&n)) fuck();
 return 0;
}

