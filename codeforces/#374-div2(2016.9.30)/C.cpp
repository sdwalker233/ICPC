#include <bits/stdc++.h>
#define MAXN 5010
using namespace std;
struct node{
	int to,next,v;
}edge[MAXN<<1];
int head[MAXN],tot=0;
int n,m,T;
int dp[MAXN][MAXN],mxstep[MAXN],in[MAXN];
int pre[MAXN][MAXN];

void addedge(int x,int y,int z)
{
	tot++;
	edge[tot].to=y;
	edge[tot].next=head[x];
	edge[tot].v=z;
	head[x]=tot;
	in[y]++;
}

void f(int x,int step)
{
	if(x==0) return;
	f(pre[x][step],step-1);
	printf("%d ",x);
}

int main()
{
	memset(head,-1,sizeof(head));
	memset(dp,0x3f,sizeof(dp));
	int i,j,x,y,z;
	cin>>n>>m>>T;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(y!=1) addedge(x,y,z);
	}
	//printf(" %d %d %d\n",edge[1].to,edge[1].next,edge[1].v);
	dp[1][0]=0;
	queue<int> qu;
	qu.push(1);
	while(!qu.empty()){
		int u=qu.front();
		qu.pop();
		for(i=head[u];~i;i=edge[i].next){
			int v=edge[i].to;
			int w=edge[i].v;
			//printf("%d %d %d %d\n",u,v,i,edge[i].next);
			in[v]--;
			if(in[v]==0) qu.push(v);
			for(j=0;j<=mxstep[u];j++){
				if(dp[v][j+1]>dp[u][j]+w){
					dp[v][j+1]=dp[u][j]+w;
					//printf("dp[%d][%d]=%d %d\n",v,j+1,dp[v][j+1],u);
					pre[v][j+1]=u;
					mxstep[v]=max(mxstep[v],j+1);
				}
			}
		}
	}
	for(i=n;i>=0;i--){
		if(dp[n][i]<=T) break;
	}
	int step=i;
	printf("%d\n",step+1);
	f(n,step);
 return 0;
}

