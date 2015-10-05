#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0xfffffff
using namespace std;
int n,m,g[1010][1010],dis[1010],p[1010];

void dijkstra(int x)
{
	int i,j,min,minj=x;
	bool vis[1010]={0};
	for(i=1;i<=n;i++) dis[i]=g[x][i];
	vis[x]=1;
	for(i=1;i<n;i++){
		min=INF;
		for(j=1;j<=n;j++)
			if(!vis[j]&&dis[j]<min){
				min=dis[j];
				minj=j;
			}
		vis[minj]=1;
		for(j=1;j<=n;j++)
			if(!vis[j]&&dis[j]>dis[minj]+g[minj][j])
				dis[j]=dis[minj]+g[minj][j];
	}
}

int DFS(int x)
{
	int i,res=0;
	if(p[x]!=-1) return p[x];
	for(i=1;i<=n;i++)
		if(dis[x]>dis[i]&&g[x][i]<INF) res+=DFS(i);
	p[x]=res;
	return res;
}

void fuck()
{
	int i,j,x,y,d;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			g[i][j]=INF;
	for(i=1;i<=n;i++)
		g[i][i]=0;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&d);
		g[x][y]=min(g[x][y],d);
		g[y][x]=min(g[y][x],d);
	}
	dijkstra(2);
	memset(p,-1,sizeof(p));
	p[2]=1;
	printf("%d\n",DFS(1));
	
}
int main()
{
	while(~scanf("%d",&n)&&n){
		scanf("%d",&m);
		fuck();
	}
 return 0;
}


