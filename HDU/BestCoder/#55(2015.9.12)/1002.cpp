#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0xfffffff
using namespace std;
int dx[]={1,0,0,-1},dy[]={0,1,-1,0};
int n,m,k;
char h[55][55];
double dp[55][55][55];

int abs(int x)
{
	return x>=0?x:-x;
}

bool ok(int x,int y)
{
	if(x<1||x>n||y<1||y>m) return 0;
	return 1;
}

void fuck()
{
	int i,j,l,p,sx,sy,ex,ey,nx,ny,div;
	double ene,ans=INF;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++){
		scanf("%s",&h[i][1]);
		for(j=1;j<=m;j++)
			dp[i][j][0]=INF;
	}
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	dp[sx][sy][0]=0;
	for(l=1;l<k;l++){
		div=k-l+1;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				dp[i][j][l]=INF;
				if(h[i][j]=='#') continue;
				for(p=0;p<4;p++){
					nx=i+dx[p];
					ny=j+dy[p];
					if(ok(nx,ny)==0) continue;
					if(h[nx][ny]=='#') continue;
					ene=(double)abs(h[i][j]-h[nx][ny])/div;
					dp[i][j][l]=min(dp[i][j][l],dp[nx][ny][l-1]+ene);
				}
			}
		}
	}
	for(i=0;i<k;i++)
		ans=min(ans,dp[ex][ey][i]);
	if(ans>INF-1) printf("No Answer\n");
	else printf("%.2lf\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}


