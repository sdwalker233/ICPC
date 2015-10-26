#include <bits/stdc++.h>
using namespace std;
int a[152],dp[152][152*152];

int main()
{
	int n,K,s,i,j,k,ans=0x7fffffff;
	memset(dp,-1,sizeof(dp));
	scanf("%d%d%d",&n,&K,&s);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dp[0][0]=0; 
	for(i=1;i<=n;i++){
		for(j=n-1;j>=0;j--){
			for(k=0;k<=i*j;k++){
				if(dp[j][k]!=-1){
					if(dp[j+1][k+i-j-1]==-1) dp[j+1][k+i-j-1]=dp[j][k]+a[i];
					else dp[j+1][k+i-j-1]=min(dp[j+1][k+i-j-1],dp[j][k]+a[i]);
				}
			}
		}
	}
	for(i=0;i<=min(s,n*n);i++)
		if(dp[K][i]!=-1) ans=min(ans,dp[K][i]);
	printf("%d\n",ans);
}
