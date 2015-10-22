#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=1000000007;
int n,m;
int dp[2][51][51][51][8];

void fuck()
{
	int i,j,k,l,p,q,ans=0,xx=0;
	bool a[51];
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				dp[xx][i][j][k][0]=1;
	for(p=1;p<=m;p++){
		memset(a,0,sizeof(a));
		scanf("%d",&k);
		memcpy(dp[xx^1],dp[xx],sizeof(dp[xx]));
		for(i=1;i<=k;i++){
			scanf("%d",&l);
			a[l]=1;
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				for(k=1;k<=n;k++)
					for(q=0;q<8;q++){
						dp[xx^1][i][j][k][q^((a[i]<<2)|(a[j]<<1)|a[k])]+=dp[xx][i][j][k][q];
						dp[xx^1][i][j][k][q^((a[i]<<2)|(a[j]<<1)|a[k])]%=mod;
					}

		xx^=1;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				ans=(ans+dp[xx][i][j][k][7])%mod;
	printf("%d\n",ans);
}

int main()
{
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		fuck();
	}
 return 0;
}