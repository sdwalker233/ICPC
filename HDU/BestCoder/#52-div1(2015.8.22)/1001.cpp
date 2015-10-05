#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0xfffffff
using namespace std;
int n,m,g[20][20],dp[200000][20];

void floyd()
{
	int i,j,k;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

void fuck()
{
	int i,j,k,ii,jj,kk,x,y,z,p,ans=INF;
	scanf("%d%d",&n,&m);
	p=(1<<n)-1;
	for(i=1;i<=p;i++)
		for(j=1;j<=n;j++)
			dp[i][j]=INF;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			g[i][j]=INF;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		g[x][y]=min(g[x][y],z);
		g[y][x]=min(g[y][x],z);
	}
	floyd();
	dp[1][1]=0;
	for(i=1;i<=p;i++){
		if((i&1)==0) continue;
		for(j=1;j<=n;j++){
			jj=(1<<(j-1));
			if((i&jj)==0) continue;
			for(k=2;k<=n;k++){
				kk=(1<<(k-1));
				if(i&kk) continue;
				//printf(" %d %d %d\n",i,j,k);
				dp[kk|i][k]=min(dp[kk|i][k],dp[i][j]+g[j][k]);
			}
		}
	}
	for(i=2;i<=n;i++){
		ans=min(ans,dp[p][i]+g[i][1]);
	}
	if(n==1) printf("0\n");
	else printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}

