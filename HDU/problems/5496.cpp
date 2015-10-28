#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define mod 1000000007
using namespace std;
int n,a[100010];
long long num[100010],dp[100010],sum[100010];
map<int,long long> mp1,mp2;

void fuck()
{
	int i;
	//mp1.clear();
	mp2.clear();
	memset(num,0,sizeof(num));
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++){
		dp[i]=(sum[i-1]+((num[i-1]-mp2[a[i]]+mod)%mod)*a[i]%mod+a[i])%mod;
		sum[i]=(sum[i-1]+dp[i])%mod;
		//mp1[a[i]]+=dp[i];
		num[i]=(num[i-1]+num[i-1]+1)%mod;
		mp2[a[i]]=(mp2[a[i]]+num[i-1]+1)%mod;
		//printf(" %d %d %d %d %d %d\n",i,dp[i],sum[i],num[i],mp1[a[i]],mp2[a[i]]);
	}
	printf("%d\n",sum[n]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}
