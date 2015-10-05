#include<stdio.h>
#include<string.h>
int k,m,n,g[501][501],match[501];
bool visit[501];

 bool hungary(int x)
 {
 	int i;
 	for(i=1;i<=n;i++)
 		if(g[x][i]&&!visit[i]){
 			visit[i]=1;
 			if(match[i]==-1||hungary(match[i])){
 				match[i]=x;
 				return 1;
 			}
 		}
 	return 0;
 }

 void run()
 {
 	int i,j,a,b,ans=0;
 	memset(g,0,sizeof(g));
 	memset(match,-1,sizeof(match));
 	for(i=1;i<=k;i++){
 		scanf("%d%d",&a,&b);
 		g[a][b]=1;
 	}
 	for(i=1;i<=m;i++){
 		memset(visit,0,sizeof(visit));
 		if(hungary(i)) ans++;
 	}
 	printf("%d\n",ans);
 }

int main()
{
	while(scanf("%d",&k)!=EOF){
		if(k==0) break;
		scanf("%d%d",&m,&n);
		run();
	}
 return 0;
}

