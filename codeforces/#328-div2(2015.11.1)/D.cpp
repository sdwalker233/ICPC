#include <bits/stdc++.h>
#define MAXN 123500
using namespace std;
struct node{
	int to,next;
}edge[MAXN<<1];
int n,m,head[MAXN],tot,fa[MAXN],intree[MAXN]={0},deep[MAXN];
int cnt=0,maxdp=0,maxlen=0,root,root2;
bool att[MAXN];

void addedge(int x,int y)
{
	++tot;
	edge[tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

void DFS1(int x,int pre,int dp)
{
	int i,p;
	fa[x]=pre;
	deep[x]=dp;
	for(i=head[x];~i;i=edge[i].next){
		p=edge[i].to;
		if(p==pre) continue;
		DFS1(p,x,dp+1);
	}
}

void spawn(int x)
{
	if(x==0||intree[x]) return;
	intree[x]=1;cnt++;
	if(maxdp<deep[x]||(maxdp==deep[x]&&x<root)){
		root=x;
		maxdp=deep[x];
	}
	spawn(fa[x]);
}

void DFS2(int x,int pre,int len)
{
	int i,p;
	if(len>maxlen||(len==maxlen&&x<root2)){
		maxlen=len;
		root2=x;
	}
	for(i=head[x];~i;i=edge[i].next){
		p=edge[i].to;
		if(intree[p]==0||p==pre) continue;
		DFS2(p,x,len+1);
	}
}

int main()
{
	int i,a,b,x;
	tot=0;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		addedge(a,b);
		addedge(b,a);
	}
	for(i=1;i<=m;i++){
		scanf("%d",&x);
		att[x]=1;
		root=x;
	}
	DFS1(root,0,0);
	for(i=1;i<=n;i++)
		if(att[i]&&!intree[i]) spawn(i);
	root2=root;
	DFS2(root,0,0);
	printf("%d\n%d\n",min(root,root2),2*cnt-maxlen-2);
 return 0;
}