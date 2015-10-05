#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int m,n,sx,sy,a[9][9],xx[4]={1,0,0,-1},yy[4]={0,1,-1,0};
bool visit[9][9],ok;

struct node{
	int x,y,t,left;
};

 int BFS()
 {
	int i;
 	queue<node> q;
 	node tmp,now;
 	tmp.x=sx;tmp.y=sy;tmp.t=0;tmp.left=5;visit[sx][sy]=1;
 	q.push(tmp);
 	while(!q.empty()){
 		now=q.front();
 		q.pop();
		if(a[now.x][now.y]==3) return now.t;
		if(a[now.x][now.y]==4){
			now.left=5;
			visit[now.x][now.y]=1;
		} 
		if(now.left==0) continue;
 		for(i=0;i<4;i++){
 			tmp.x=now.x+xx[i];
			tmp.y=now.y+yy[i];
			if(tmp.x<1||tmp.x>m||tmp.y<1||tmp.y>n||a[tmp.x][tmp.y]==0||visit[tmp.x][tmp.y]) continue;
			tmp.t=now.t+1;
			tmp.left=now.left-1;
			q.push(tmp);
 		}
 	}
	return -1;
 }

 void run()
 {
	int i,j;
	memset(visit,0,sizeof(visit));
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==2) {sx=i;sy=j;}
		}
	printf("%d\n",BFS());
 }

int main(){
	int t;
	scanf("%d",&t);
	while(t--)
		run();
 return 0;
}
