#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node1{
	int x,y;
}edge[1000000];
int n,m,g[1001][1001];

int cal4()
{
	int i,j,cnt=0,u1,u2,v1,v2;
	for(i=1;i<=m;i++){
		u1=edge[i].x;v1=edge[i].y;
		for(j=i+1;j<=m;j++){
			u2=edge[j].x;v2=edge[j].y;
			if(u1==u2||u1==v2||v1==u2||v1==v2) continue;
			if(g[u1][u2]&&g[u1][v2]&&g[v1][u2]&&g[v1][v2]){
				//printf("%d %d %d %d\n",u1,v1,u2,v2);
				cnt++;
			}
		}
	}
	return cnt/3;
}
int cal3()
{
	int i,j,cnt=0;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(g[edge[i].x][j]&&g[edge[i].y][j]) cnt++;
		}
	}
	return cnt/3;
}

 void run()
 {
 	int i,j,x,y,cnt=0;
 	memset(g,0,sizeof(g));
 	for(i=1;i<=n;i++)
 		scanf("%d%d",&x,&y);
 	for(i=1;i<=m;i++){
 		scanf("%d%d",&x,&y);
 		edge[i].x=x;
 		edge[i].y=y;
 		g[x][y]=g[y][x]=1;
	}
	x=cal4();
	y=cal3();
	if(x) printf("4 %d\n",x);
	else if(y) printf("3 %d\n",y);
	else if(m) printf("2 %d\n",m);
	else printf("1 %d\n",n);
 }

int main()
{
	while(~scanf("%d%d",&n,&m))
		run();
 return 0;
}

