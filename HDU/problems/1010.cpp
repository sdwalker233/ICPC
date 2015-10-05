#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n,m,t,sx,sy,ex,ey;
bool maze[9][9],ok;

 void DFS(int x,int y,int step)
 {
 	if(ok) return;
 	if(abs(x-ex)+abs(y-ey)>t-step) return;
 	if(x==ex&&y==ey){
 		if(step==t) ok=1;
		return;
	}
	if(step==t) return;
	//printf("%d %d %d\n",x,y,step);
 	maze[x][y]=1;
 	if(x>1&&!maze[x-1][y]) DFS(x-1,y,step+1);
 	if(x<n&&!maze[x+1][y]) DFS(x+1,y,step+1);
 	if(y>1&&!maze[x][y-1]) DFS(x,y-1,step+1);
 	if(y<m&&!maze[x][y+1]) DFS(x,y+1,step+1);
 	maze[x][y]=0;
 }
 	
 void init()
 {
 	int i,j,wall=1;
 	char s;
 	ok=0;
 	for(i=1;i<=n;i++){
 		getchar();
 		for(j=1;j<=m;j++){
 			s=getchar();
 			switch(s){
 				case('.'):maze[i][j]=0;break;
 				case('X'):maze[i][j]=1;wall++;break;
 				case('S'):maze[i][j]=0;sx=i;sy=j;break;
 				case('D'):maze[i][j]=0;ex=i;ey=j;break;
 			}
 		}
 	}
 	getchar();
 	if((abs(sx-ex)+abs(sy-ey)-t)%2!=0||m*n-wall<t){
 		printf("NO\n");
 		return;
 	}
 	DFS(sx,sy,0);
 	if(ok) printf("YES\n");
 	else printf("NO\n");
 }
				
int main()
{
	while(1){
		scanf("%d%d%d",&n,&m,&t);
		if(!n&&!m&&!t) return 0;
		init();
	}
 return 0;
}

