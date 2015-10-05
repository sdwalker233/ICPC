#include<stdio.h>
#include<string.h>
using namespace std;
int n,k,maze[101][101],v[101][101],xx[]={1,0,0,-1},yy[]={0,1,-1,0};

 int max(int x,int y)
 {
 	return x>y?x:y;
 }

 int DFS(int x,int y)
 {
 	int i,j,nx,ny;
 	if(v[x][y]) return v[x][y];
 	//printf(" %d %d\n",x,y);
 	for(i=0;i<4;i++){
 		for(j=1;j<=k;j++){
 			nx=x+j*xx[i];
 			ny=y+j*yy[i];
 			//printf("  %d %d\n",nx,ny);
 			if(nx<1||nx>n||ny<1||ny>n) break;
			if(maze[nx][ny]<=maze[x][y]) continue;
 			v[x][y]=max(v[x][y],DFS(nx,ny));
 		}
 	}
 	v[x][y]+=maze[x][y];
 	return v[x][y];
 }

 void run()
 {
 	int i,j;
 	memset(v,0,sizeof(v));
 	for(i=1;i<=n;i++)
 		for(j=1;j<=n;j++)
 			scanf("%d",&maze[i][j]);
 	DFS(1,1);
 	printf("%d\n",v[1][1]);
 }

int main()
{
	while(1){
		scanf("%d%d",&n,&k);
		if(n==-1&&k==-1) break;
		run();
	}
 return 0;
}

