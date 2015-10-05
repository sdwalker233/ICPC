#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100010],dp[100010],k[100010]={0};

int main()
{
	int n,i,j,p,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dp[1]=ans=1;
	for(i=2;i<=n;i++){
		if(a[i]<a[i-1]) dp[i]=1;
		else dp[i]=dp[i-1]+1;
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
 return 0;
}