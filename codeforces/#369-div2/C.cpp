#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int c[110],a[110][110];
long long dp[110][110][110];
int main()
{
	int i,j,p,q;
	memset(dp,0x3f,sizeof(dp));
	memset(dp[0],0,sizeof(dp[0]));
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%d",&c[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=min(i,k);j++)
			if(c[i]==0)
				for(p=1;p<=m;p++){
					dp[i][j][p]=dp[i-1][j][p];
					for(q=1;q<=m;q++){
						if(q==p) continue;
						if(j>1) dp[i][j][p]=min(dp[i][j][p],dp[i-1][j-1][q]);
					}
					dp[i][j][p]+=a[i][p];
				}
			else{
				p=c[i];
				dp[i][j][p]=dp[i-1][j][p];
				for(q=1;q<=m;q++){
					if(q==p) continue;
					if(j>1) dp[i][j][p]=min(dp[i][j][p],dp[i-1][j-1][q]);
				}
			}
	long long ans=0x7fffffffffffffff;
	for(i=1;i<=m;i++)
		 ans=min(dp[n][k][i],ans);
	if(ans>=0x7ffffffffffffff) printf("-1\n");
	else cout<<ans<<endl;
 return 0;
}

