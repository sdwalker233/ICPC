#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;
int n,m,W,w[MAXN],b[MAXN];
int fa[MAXN];
int dp[MAXN][MAXN];
vector<int> group[MAXN];

int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

int main()
{
	int i,j;
	scanf("%d%d%d",&n,&m,&W);
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=n;i++) scanf("%d",&w[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	for(i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int fx=find(x),fy=find(y);
		fa[fx]=fy;
	}
	for(i=1;i<=n;i++){
		group[find(i)].push_back(i);
	}
	int cnt=0;
	for(i=1;i<=n;i++){
		if(group[i].size()) group[++cnt]=group[i];
	}
	/*for(i=1;i<=cnt;i++){
		printf("%d:",i);
		for(auto it:group[i]) printf(" %d",it);
		printf("\n");
	}*/
	int cur=0;
	for(i=1;i<=cnt;i++){
		int sumw=0,sumb=0;
		for(auto it:group[i]){
			sumw+=w[it];
			sumb+=b[it];
		}
		for(j=0;j<=W;j++) dp[i][j]=dp[i-1][j];
		for(j=W;j>=sumw;j--){
			dp[i][j]=max(dp[i][j],dp[i-1][j-sumw]+sumb);
		}
		for(auto it:group[i])
			for(j=W;j>=w[it];j--){
				dp[i][j]=max(dp[i][j],dp[i-1][j-w[it]]+b[it]);
			}

		/*printf("%d:",i);
		for(j=0;j<=W;j++) printf(" %d",dp[i][j]);
		printf("\n");*/
	}
	int ans=0;
	for(i=0;i<=W;i++) ans=max(ans,dp[cnt][i]);
	printf("%d\n",ans);
 return 0;
}

