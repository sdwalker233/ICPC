#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,q,g[1010][1010],x1,y1,x2,y2;
int dx[]={1,0,0,-1},dy[]={0,1,-1,0};
int vis[1010][1010],ok;

void DFS(int x,int y,int num,int dir)
{
	if(num>3) return;
	if(x==x2&&y==y2) ok=1;
	if(ok) return;
	vis[x][y]=num;
	if(!(x==x1&&y==y1)&&g[x][y]!=0) return;
	//printf(" %d %d %d %d\n",x,y,num,dir);
	int i,nx,ny,p;
	for(i=0;i<4;i++){
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx<1||nx>n||ny<1||ny>m) continue;
		if(dir==i) p=num;
		else p=num+1;
		if(vis[nx][ny]!=-1&&vis[nx][ny]<p) continue;
		DFS(nx,ny,p,i);
	}
}

void fuck()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&g[i][j]);
	scanf("%d",&q);
	for(i=1;i<=q;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		memset(vis,-1,sizeof(vis));
		ok=0;
		if(g[x1][y1]==g[x2][y2]&&g[x1][y1]&&!(x1==x2&&y1==y2))	DFS(x1,y1,0,-1);
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
}

int main()
{
	while(~scanf("%d%d",&n,&m)&&n&&m)
		fuck();
 return 0;
}