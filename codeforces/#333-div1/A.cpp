#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0xfffffff
using namespace std;

int g[500][500]={0},g1[500][500];

int main()
{
	int n,m,i,j,k,x,y,t1=-1,t2=-1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		g[x][y]=g[y][x]=1;
	}
	memcpy(g1,g,sizeof(g));
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(g[i][j]==0) g[i][j]=INF;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[j][k]);
			}
	t1=g[1][n];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(g1[i][j]==1) g1[i][j]=INF;
			else g1[i][j]=1;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				g1[i][j]=min(g1[i][j],g1[i][k]+g1[j][k]);
			}
	t2=g1[1][n];
	if(t1>=INF||t2>=INF){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",max(t1,t2));
 return 0;
}