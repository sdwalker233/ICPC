#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 100010
using namespace std;
struct node{
	int to,next;
}edge[MAXN<<1];
int tot,head[MAXN];
int n,a[MAXN],root,v[MAXN];
bool impossible,vis[MAXN];

struct cmp{
	bool operator ()(int x,int y){
		if(a[x]==a[y]) return x<y;
		return a[x]<a[y];
	}
};
priority_queue<int,vector<int>,cmp> qu1;
priority_queue<int> qu2;

void addedge(int x,int y)
{
	++tot;
	edge[tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

void DFS(int x,int pre)
{
	if(impossible) return;
	int i,cnt=0;
	for(i=head[x];~i;i=edge[i].next){
		if(edge[i].to==pre) continue;
		if(a[edge[i].to]==a[x]) cnt++;
		if(a[edge[i].to]>a[x]) impossible=1;
		DFS(edge[i].to,x);
	}
	if(cnt==0){
		v[x]=a[x];
		vis[a[x]]=1;
	}
	if(cnt>1) impossible=1;
}

void fuck()
{
	int i,j,x,y;
	tot=0;
	memset(head,-1,sizeof(head));
	memset(v,0,sizeof(v));
	memset(vis,0,sizeof(vis));
	while(!qu1.empty()) qu1.pop();
	while(!qu2.empty()) qu2.pop();
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	for(i=1;i<=n;i++)
		if(a[i]==n){
			int cnt=0;
			for(j=head[i];~j;j=edge[j].next){
				if(a[edge[j].to]==n) ++cnt;
			}
			if(cnt<=1) break;
		}
	root=i;
	impossible=0;
	DFS(root,0);
	if(impossible){
		printf(" Impossible\n");
		return;
	}
	for(i=1;i<=n;i++)
		if(!v[i]) qu1.push(i);
	for(i=n;i>=1;i--){
		if(vis[i]) continue;
		while(!qu1.empty()&&a[qu1.top()]>=i){
			qu2.push(qu1.top());
			qu1.pop();
		}
		if(qu2.empty()||a[qu2.top()]<i){
			printf(" Impossible\n");
			return;	
		}
		v[qu2.top()]=i;
		qu2.pop();
	}
	for(i=1;i<=n;i++) printf(" %d",v[i]);
	printf("\n");
}

int main()
{
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d:",i);
		fuck();
	}
 return 0;
}

