#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int to,next;
}edge[3000];
int n,tot,num[1010],head[1010],cnt;
bool ok,vis[1010];

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
	cnt++;
	for(i=head[x];i!=-1;i=edge[i].next){
		if(vis[edge[i].to]) continue;
		DFS(edge[i].to);
	}
}

void fuck()
{
	int i,x,y,t[5]={0};
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
	memset(head,-1,sizeof(head));
	tot=-1;ok=1;cnt=0;
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(x==y) continue;
		addedge(x,y);
		addedge(y,x);
		num[x]++;
		num[y]++;
	}
	DFS(1);
	if(cnt!=n){
		printf("NO\n");
		return;
	}
	for(i=1;i<=n;i++){
		if(num[i]>3) ok=0;
		else t[num[i]]++;
	}
	if(!ok){
		printf("NO\n");
		return;
	}
	if((t[1]==0&&t[3]==0)||(t[1]==1&&t[3]==1)||(t[1]==2&&t[3]==2)||(t[1]==2&&t[3]==0))
		printf("YES\n");
	else printf("NO\n");
}

int main()
{
	while(~scanf("%d",&n))
		fuck();
 return 0;
}


