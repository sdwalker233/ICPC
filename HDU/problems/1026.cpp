#include<stdio.h>
#include<queue>
using namespace std;
struct node{
	int x,y,cost;
};
struct node2{
	int x,y;
}front[100][100],route[10000];
int m,n,xx[4]={1,0,0,-1},yy[4]={0,1,-1,0},len;
char g[100][100];
bool ok;
bool operator<(node a,node b){
    return a.cost>b.cost;
}

 void BFS()
 {
 	int i,j,xxx,yyy,xxx1,time;
 	bool visit[100][100]={0};
 	node now,tmp;
 	priority_queue<node> q1;
 	tmp.x=0;tmp.y=0;tmp.cost=0;
 	visit[0][0]=1;
 	q1.push(tmp);
 	while(!q1.empty()){
 		now=q1.top();
 		q1.pop();
 		//printf("%d %d %d\n",now.x,now.y,now.cost);
 		if(now.x==n-1&&now.y==m-1){
		 	ok=1;
			break;
		}
 		for(i=0;i<4;i++){
 			tmp.x=now.x+xx[i];
 			tmp.y=now.y+yy[i];
 			if(tmp.x<0||tmp.x>n-1||tmp.y<0||tmp.y>m-1||g[tmp.x][tmp.y]=='X'||visit[tmp.x][tmp.y]!=0)
			 	continue;
 			tmp.cost=now.cost+1;
 			if(g[tmp.x][tmp.y]!='.')
				tmp.cost+=g[tmp.x][tmp.y]-'0';
			visit[tmp.x][tmp.y]=1;
			q1.push(tmp);
			front[tmp.x][tmp.y].x=now.x;
			front[tmp.x][tmp.y].y=now.y;
			
			}
		}
		if(ok==0) return;
		len=1;
		route[0].x=xxx=now.x;
		route[0].y=yyy=now.y;
		while(xxx!=0||yyy!=0){
			route[len++]=front[xxx][yyy];
			xxx1=front[xxx][yyy].x;
			yyy=front[xxx][yyy].y;
			xxx=xxx1;
		}
		time=1;
		printf("It takes %d seconds to reach the target position, let me show you the way.\n",now.cost);
		for(i=len-2;i>=0;i--){
			printf("%ds:(%d,%d)->(%d,%d)\n",time++,route[i+1].x,route[i+1].y,route[i].x,route[i].y);
			if(g[route[i].x][route[i].y]!='.')
				for(j=1;j<=g[route[i].x][route[i].y]-'0';j++)
					printf("%ds:FIGHT AT (%d,%d)\n",time++,route[i].x,route[i].y);
			}
 }

 void run()
 {
 	int i,j;
 	getchar();
 	for(i=0;i<n;i++){
 		for(j=0;j<m;j++)
 			g[i][j]=getchar();
 		getchar();
 	}
 	ok=0;
 	BFS();
 	if(ok==0) printf("God please help our poor hero.\n");
	printf("FINISH\n");
 }

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
		run();
 return 0;
}

