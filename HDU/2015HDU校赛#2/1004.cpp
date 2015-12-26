#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXV 10000
#define INF 0xfffffff
#define MAXN 110
using namespace std;
int g[MAXN][MAXN],n;

int Prim(int x)
{
	int i,j,mini;
	int dis[MAXN],sum=0;
	bool vis[MAXN]={0};
	vis[x]=1;
	for(i=1;i<=n;i++)
		dis[i]=g[x][i];
	for(j=1;j<n;j++){
		mini=x;
		for(i=1;i<=n;i++)
			if(!vis[i]&&dis[i]<dis[mini])
				mini=i;
		vis[mini]=1;sum+=dis[mini];
		for(i=1;i<=n;i++)
			if(!vis[i]&&g[mini][i]<dis[i])
				dis[i]=g[mini][i];
	}
	return sum;
}

void fuck()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			scanf("%d",&g[i][j]);
			g[i][j]=MAXV-g[i][j];
		}
	printf("%d\n",(n-1)*MAXV-Prim(1));
	
}
int main()
{
	while(~scanf("%d",&n))
		fuck(); 
 return 0;
}


