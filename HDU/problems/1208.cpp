#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int a[40][40];
long long dp[40][40];

void fuck()
{
	int i,j;
	memset(dp,0,sizeof(dp));
	dp[1][1]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			scanf("%1d",&a[i][j]);
			if(a[i][j]==0) continue;
			if(i+a[i][j]<=n) dp[i+a[i][j]][j]+=dp[i][j];
			if(j+a[i][j]<=n) dp[i][j+a[i][j]]+=dp[i][j];
		}
	cout<<dp[n][n]<<endl;
}

int main()
{
	while(~scanf("%d",&n)&&n!=-1)
		fuck();
 return 0;
}

