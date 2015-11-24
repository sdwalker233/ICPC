#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int a[1100][1100];
int dp[1100][1100];

void fuck()
{
	int i,j;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			dp[i][j]=0x7fffffff;
		}
	dp[1][2]=a[1][1]*a[1][2];
	dp[2][1]=a[1][1]*a[2][1];
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if((i+j)%2==0) continue;
			if(i>2) dp[i][j]=min(dp[i][j],dp[i-2][j]+a[i-1][j]*a[i][j]);
			if(i>1&&j>1) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+a[i-1][j]*a[i][j]);
			if(i>1&&j>1) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+a[i][j-1]*a[i][j]);
			if(j>2) dp[i][j]=min(dp[i][j],dp[i][j-2]+a[i][j-1]*a[i][j]);
		}
	}
	printf("%d\n",dp[n][m]);
}

int main()
{
	while(~scanf("%d%d",&n,&m))
		fuck();
 return 0;
}