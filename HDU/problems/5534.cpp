#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,f[2020],dp[2020];

void fuck()
{
	int i,j;
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d",&f[i]);
	}
	for(i=1;i<=n-2;i++){
		dp[i]=f[i+1]-f[1];
		for(j=0;j<i;j++)
			dp[i]=max(dp[i],dp[i-j]+f[j+1]-f[1]);
	}
	printf("%d\n",dp[n-2]+n*f[1]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}