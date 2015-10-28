#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,w[10010];
double v[10010],dp[10010];

void fuck()
{
	int i,j;
	double mn=1;
	for(i=1;i<=n;i++){
		scanf("%d%lf",&w[i],&v[i]);
		v[i]=1-v[i];
	}
	for(i=0;i<=m;i++)
		dp[i]=1;
	for(i=1;i<=n;i++){
		for(j=m;j>=w[i];j--)
			dp[j]=min(dp[j],dp[j-w[i]]*v[i]);
	}
	for(i=0;i<=m;i++)
		mn=min(mn,dp[i]);
	printf("%.1lf%%\n",(1-mn)*100);
}

int main()
{
	while(~scanf("%d%d",&m,&n),n||m)
		fuck();
 return 0;
}