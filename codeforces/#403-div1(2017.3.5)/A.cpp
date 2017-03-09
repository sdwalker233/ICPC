#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
struct node{
	int to,next;
}edge[MAXN<<1],edge2[MAXN<<2];
int n,tot,tot2,head[MAXN],head2[MAXN],col[MAXN],vis[MAXN],b[MAXN];

void addedge(int x,int y)
{
	++tot;
	edge[tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

void DFS(int x)
{
	int i,j,k=1;
	vis[x]=1;
	b[col[x]]=x;
	for(i=head[x];~i;i=edge[i].next){
		b[col[edge[i].to]]=x;
	}
	for(i=head[x];~i;i=edge[i].next){
		if(!col[edge[i].to]){
			for(j=k;j<=n;j++)
				if(b[j]!=x) break;
			col[edge[i].to]=j;
			k=j+1;
		}
	}
	for(i=head[x];~i;i=edge[i].next){
		if(!vis[edge[i].to]) DFS(edge[i].to);	
	}
}

int main()
{
	int i,x,y;
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	memset(head2,-1,sizeof(head2));
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	col[1]=1;
	DFS(1);
	int cnt=0;
	for(i=1;i<=n;i++) b[col[i]]=n+1;
	for(i=1;i<=n;i++)
		if(b[i]==n+1) cnt++;
	printf("%d\n",cnt);
	for(i=1;i<=n;i++) printf("%d ",col[i]);
 return 0;
}

