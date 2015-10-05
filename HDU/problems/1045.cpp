#include<stdio.h>
#include<string.h>
int n,max;
char g[5][5];
bool ok[5][5];

 void DFS(int x,int step)
 {
    int i,j,k;
    bool ok2[5][5];
    //printf("%d\n",x);
    if(step>max) max=step;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            ok2[i][j]=ok[i][j];
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j){
            if((i-1)*n+j<=x||ok[i][j]||g[i][j]=='X') continue;
            for(k=i;k<=n&&g[k][j]!='X';++k) ok[k][j]=1;
            for(k=j;k<=n&&g[i][k]!='X';++k) ok[i][k]=1;
            DFS((i-1)*n+j,step+1);
            for(k=i;k<=n&&g[k][j]!='X';++k) ok[k][j]=ok2[k][j];
            for(k=j;k<=n&&g[i][k]!='X';++k) ok[i][k]=ok2[i][k];
                }
 }

 void run()
 {
 	int i,j;
 	memset(ok,0,sizeof(ok));
 	max=0;
 	getchar();
 	for(i=1;i<=n;++i){
 		for(j=1;j<=n;++j)
 			g[i][j]=getchar();
 		getchar();
 	}
 	DFS(0,0);
 	printf("%d\n",max);
 }

int main()
{
	while(scanf("%d",&n)!=EOF&&n)
		run();
 return 0;
}

