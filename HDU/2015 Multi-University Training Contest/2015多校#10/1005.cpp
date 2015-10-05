#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[1010],b[1010],w[1010];
int dp[2010];

void fuck()
{
	int i,j,x,y;
	bool ok;
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&w[i],&a[i],&b[i]);
	}
	for(i=1;i<=n;i++){
		ok=0;
		for(j=m;j>=w[i];j--)
			if(dp[j]<dp[j-w[i]]+a[i]+b[i]){
				dp[j]=dp[j-w[i]]+a[i]+b[i];
				ok=1;
			}
		if(ok)
		for(j=w[i];j<=m;j++)
			dp[j]=max(dp[j],dp[j-w[i]]+a[i]);
	}
	/*for(i=1;i<=n;i++){
		memset(ok,0,sizeof(ok));
		for(j=w[i];j<=m;j++){
			if(ok[j-w[i]]==0){
				if(dp[j]<dp[j-w[i]]+a[i]+b[i]){
					dp[j]=dp[j-w[i]]+a[i]+b[i];
					ok[j]=1;
				}
			}
			else{
				if(dp[j]<dp[j-w[i]]+a[i]){
					dp[j]=dp[j-w[i]]+a[i];
					ok[j]=1;
				}
			}
		}
	}*/
	printf("%d\n",dp[m]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}


