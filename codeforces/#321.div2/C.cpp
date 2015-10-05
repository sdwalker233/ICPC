#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int to,next;
}edge[400010];
int n,m,a[200010],tot=0,head[200010],cnt=0;
bool vis[200010]={0};

void addedge(int x,int y)
{
	++tot;
	edge[tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

void DFS(int x,int num)
{
	int i,p,t=0;
	vis[x]=1;
	if(num>m) return;
	for(i=head[x];~i;i=edge[i].next){
		p=edge[i].to;
		if(vis[p]) continue;
		t=1;
		if(a[p]) DFS(p,num+1);
		else DFS(p,0);
	}
	//printf(" %d %d %d\n",x,num,t);
	if(t==0) cnt++;
}

int main()
{
	int i,x,y;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	DFS(1,a[1]);
	printf("%d\n",cnt);
 return 0;
}


