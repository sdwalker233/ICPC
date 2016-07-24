#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
struct node{
	int to,nxt;
}edge[MAXN<<2];
int n,k;
int a[MAXN]={0},size[MAXN]={0},head[MAXN],tot=0;
long long ans=0;

void addedge(int x,int y)
{
	++tot;
	edge[tot].to=y;
	edge[tot].nxt=head[x];
	head[x]=tot;
}

void DFS(int x,int fa)
{
	int i;
	if(a[x]) size[x]++;
	for(i=head[x];~i;i=edge[i].nxt){
		if(edge[i].to==fa) continue;
		DFS(edge[i].to,x);
		size[x]+=size[edge[i].to];
		ans+=min(size[edge[i].to],2*k-size[edge[i].to]);
	}
	//printf(" %d %d\n",x,size[x]);
}

int main()
{
	int i,x,y;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&k);
	for(i=1;i<=2*k;i++){
		scanf("%d",&x);
		a[x]=1;
	}
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	DFS(1,0);
	cout<<ans<<endl;
 return 0;
}

