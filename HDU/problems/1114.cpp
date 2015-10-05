#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0xfffffff
using namespace std;
int n,m,w[510],v[510];
int dp[10010];

void fuck()
{
	int e,f,i,j;
	scanf("%d%d",&e,&f);
	m=f-e;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&v[i],&w[i]);
	for(i=1;i<=m;i++) dp[i]=INF;
	dp[0]=0;
	for(i=1;i<=n;i++){
		for(j=w[i];j<=m;j++){
			dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	if(dp[m]>=INF) printf("This is impossible.\n");
	else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[m]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		fuck();
 return 0;
}

