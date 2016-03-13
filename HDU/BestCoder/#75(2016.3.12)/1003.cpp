#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=1000000007;
int n;
long long dp[2010][5];

void fuck()
{
	int i;
	scanf("%d",&n);
	memset(dp,0,sizeof(dp));
	dp[1][1]=26;
	for(i=2;i<=n;i++){
		dp[i][1]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][3])*25%mod;
		dp[i][2]=dp[i-1][1];
		dp[i][3]=dp[i-1][2];
	}
	printf("%d\n",(dp[n][1]+dp[n][2]+dp[n][3])%mod);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}