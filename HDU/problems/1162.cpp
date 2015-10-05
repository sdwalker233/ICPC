#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;
struct node{
	double x,y;
}a[110];
int n;
double g[110][110];

double Prim(int x)
{
	double dis[110],min,sum=0;
	int i,j,minj;
	bool vis[110]={0};
	for(i=1;i<=n;i++)
		dis[i]=g[1][i];
	vis[1]=1;
	for(i=1;i<n;i++){
		min=INF;
		for(j=1;j<=n;j++){
			if(vis[j]) continue;
			if(dis[j]<min){
				min=dis[j];
				minj=j;
			}
		}
		sum+=dis[minj];
		//printf(" %lf %d\n",dis[minj],minj);
		vis[minj]=1;
		for(j=1;j<=n;j++){
			if(!vis[j]&&dis[j]>g[minj][j]){
				dis[j]=g[minj][j];
			}
		}
	}
	return sum;
}

void fuck()
{
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	for(i=1;i<=n;i++){
		g[i][i]=INF;
		for(j=i+1;j<=n;j++)
			g[i][j]=g[j][i]=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
	}
	printf("%.2lf\n",Prim(1));
}

int main()
{
	while(~scanf("%d",&n))
		fuck();
 return 0;
}