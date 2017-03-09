#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
struct node{
	int to,next;
}edge[MAXN<<1];
int n,m,k,tot,head[MAXN],vis[MAXN];
vector<int> v;

void addedge(int x,int y)
{
	++tot;
	edge[tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

void DFS(int x)
{
	int i;
	vis[x]=1;
	v.push_back(x);
	for(i=head[x];~i;i=edge[i].next){
		if(!vis[edge[i].to]){
			DFS(edge[i].to);
			v.push_back(x);
		}
	}
}

int main()
{
	int i,x,y;
	memset(head,-1,sizeof(head));
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	DFS(1);
	int p=2*n/k,num=v.size(),cnt=0;
	if(p*k<2*n) p++;
	for(i=0;i<num;i++){
		if(i%p==0) printf("%d ",min(p,num-i));
		printf("%d ",v[i]);
		if((i+1)%p==0){
			printf("\n");
			cnt++;
		}
	}
	if(num%p) cnt++;
	for(i=cnt+1;i<=k;i++)
		printf("\n1 1");
 return 0;
}

