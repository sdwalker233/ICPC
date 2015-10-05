#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int to,next;
}edge[3000];
int n,tot,num[3000],head[3000];
bool ok;

void addedge(int x,int y)
{
	++tot;
	edge[tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

void DFS(int x,int deep,int pre)
{
	int i,cnt=0;
	if(!ok) return;
	for(i=head[x];i!=-1;i=edge[i].next){
		if(edge[i].to==pre) continue;
		cnt++;
		DFS(edge[i].to,deep+1,x);
	}
	if(num[deep]==-1) num[deep]=cnt;
	else if(num[deep]!=cnt) ok=0;
}

void fuck()
{
	int i,x,y;
	memset(num,-1,sizeof(num));
	memset(head,-1,sizeof(head));
	tot=-1;ok=1;
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	DFS(1,0,-1);
	if(ok) printf("YES\n");
	else printf("NO\n");
}

int main()
{
	while(~scanf("%d",&n))
		fuck();
 return 0;
}


