#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int a,b,c;
}p[1010];
int n,t;
int dp[3010];

bool cmp(node x,node y)
{
	return x.c*y.b<x.b*y.c;
}

void fuck()
{
	int i,j,mx=0;
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
	}
	sort(p+1,p+n+1,cmp);
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++)
		for(j=t;j>=p[i].c;j--)
			dp[j]=max(dp[j],dp[j-p[i].c]+p[i].a-p[i].b*j);
	for(i=0;i<=t;i++)
		mx=max(dp[i],mx);
	printf("%d\n",mx);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}


