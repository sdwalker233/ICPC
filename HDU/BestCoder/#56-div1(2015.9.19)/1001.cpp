#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000007
using namespace std;
int a[1010];
long long dp[1010][1010];
int n,p;

void fuck()
{
	int i,j,x;
	long long ans=0;
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		a[i]=(x%p+p)%p;
	}
	dp[0][0]=1;
	for(i=1;i<=n;i++){
		memcpy(dp[i],dp[i-1],sizeof(dp[i-1]));
		for(j=0;j<p;j++){
			dp[i][(a[i]+j)%p]=(dp[i][(a[i]+j)%p]+dp[i-1][j])%mod;
		}
	}
	printf("%I64d\n",dp[n][0]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}


