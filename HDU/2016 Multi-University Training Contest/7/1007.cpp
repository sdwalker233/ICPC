#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 1010
using namespace std;
struct E{
	int to,next,index,v;
}edge[MAXN<<1];
struct node{
	int c,b,index,f;
}a[MAXN];
int head[MAXN],tot;
int n,m,f[MAXN][MAXN],over[MAXN][MAXN];
long long dp[MAXN][MAXN];

bool cmp1(const node& x,const node& y)
{
	return x.b<y.b;
}

void addedge(int x,int y,int in)
{
	++tot;
	edge[tot].to=y;
	edge[tot].index=in;
	edge[tot].next=head[x];
	edge[tot].v=-1;
	head[x]=tot;
}

long long gao(int x,int pre,int j)
{
	long long ret=0;
	int i,p;
	for(i=head[x];~i;i=edge[i].next){
		p=edge[i].to;
		if(p==pre) continue;
		ret+=dp[p][f[p][j]];
		//ret+=gao(p,x,j);
	}
	return ret;
}

void DFS(int x,int pre)
{
	int i,j,k,p;
	for(i=head[x];~i;i=edge[i].next){
		p=edge[i].to;
		if(p==pre) continue;
		DFS(p,x);
	}
	for(i=0;i<=m;i++){
		if(i&&a[i].c!=x) continue;
		//printf(" %d %d\n",x,i);
		dp[x][i]=a[i].b*over[x][i]+gao(x,pre,i);
	}
	p=m;
	for(i=m;i>=0;i--){
		if(dp[x][i]>dp[x][p]){
			p=i;
		}
		f[x][i]=p;
	}
	//printf(" %d\n",x);
}

void DFS2(int x,int pre,int v)
{
	int i,p;
	for(i=head[x];~i;i=edge[i].next){
		p=edge[i].to;
		if(p==pre) continue;
		edge[i].v=a[f[p][v]].b-a[v].b;
		DFS2(p,x,f[p][v]);
	}
}

void fuck()
{
	int i,j,x,y;
	memset(head,-1,sizeof(head));
	memset(dp,0,sizeof(dp));
	memset(over,0,sizeof(over));
	tot=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y,i);
		addedge(y,x,i);
	}
	for(i=1;i<=m;i++){
		scanf("%d%d",&a[i].c,&a[i].b);
		a[i].index=i;
	}
	a[0].c=a[0].b=0;
	sort(a+1,a+m+1,cmp1);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			if(a[j].c==i) over[i][j]++;
		for(j=m-1;j>=0;j--){
			over[i][j]+=over[i][j+1];
		}
	}
	DFS(1,0);
	/*for(i=1;i<=n;i++){
		for(j=0;j<=m;j++)
			printf(" %d",over[i][j]);
		printf("\n");
	}
	printf("\n");
	for(i=1;i<=n;i++){
		for(j=0;j<=m;j++)
			printf(" %d",dp[i][j]);
		printf("\n");
	}
	printf("\n");
	for(i=1;i<=n;i++){
		for(j=0;j<=m;j++)
			printf(" %d",f[i][j]);
		printf("\n");
	}*/
	printf("%lld\n",dp[1][0]);
	DFS2(1,-1,0);
	vector<int> w;
	for(i=1;i<=tot;i++){
		if(edge[i].v!=-1) w.push_back(edge[i].v);
	}
	for(i=0;i<w.size()-1;i++) printf("%d ",w[i]);
	printf("%d\n",w[i]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

