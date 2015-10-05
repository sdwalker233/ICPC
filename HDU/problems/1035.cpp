#include<stdio.h>
int m,n,xx[]={-1,1,0,0},yy[]={0,0,1,-1};
char g[11][11];

 void run()
 {
 	int i,j,x=1,y,d,step[101][101]={0},nx,ny;
 	scanf("%d",&y);
 	getchar();
 	for(i=1;i<=m;i++){
 		for(j=1;j<=n;j++)
 			g[i][j]=getchar();
 		getchar();
 	}
 	step[x][y]=1;
 	while(1){
 		
 		if(g[x][y]=='N') d=0;
 		if(g[x][y]=='S') d=1;
 		if(g[x][y]=='E') d=2;
 		if(g[x][y]=='W') d=3;
 		nx=x+xx[d];ny=y+yy[d];
 		if(nx<1||nx>m||ny<1||ny>n){
 			printf("%d step(s) to exit\n",step[x][y]);
 			return;
 		}
 		if(step[nx][ny]){
		 	printf("%d step(s) before a loop of %d step(s)\n",step[nx][ny]-1,step[x][y]-step[nx][ny]+1);
		 	return;
		 }
		else{
			step[nx][ny]=step[x][y]+1;
			x=nx;y=ny;
		}
	}		
 }

int main()
{
	while(scanf("%d%d",&m,&n)!=EOF&&n)
		run();
 return 0;
}

