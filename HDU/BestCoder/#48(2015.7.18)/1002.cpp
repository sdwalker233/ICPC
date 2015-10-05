#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,head[100010],tot,visit[100010],num[3];
struct node{
	int to,next;
}edge[200010];
bool ok;

void addedge(int x,int y)
{
	++tot;
	edge[tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

void DFS(int x,int col)
{
	int i,u;
	if(ok==0) return;
	visit[x]=col;
	num[col]++;
	for(i=head[x];i!=-1;i=edge[i].next)
	{
		u=edge[i].to;
		if(visit[u]){
			if(visit[u]!=3-col){
				ok=0;
				return;
			}
		}
		else DFS(u,3-col);
	}
}

void fuck()
{
	int i,j,a,b,sum1=0,sum2=0;
	tot=0;ok=1;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	memset(visit,0,sizeof(visit));
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		addedge(a,b);
		addedge(b,a);
	}
	for(i=1;i<=n;i++){
		num[1]=num[2]=0;
		if(ok&&visit[i]==0)
			DFS(i,1);
		sum1+=max(num[1],num[2]);
		sum2+=min(num[1],num[2]);
	}
	if(ok){
		if((sum1==1||sum1==0)&&sum2==0) printf("Poor wyh\n");
		else{
			if(sum2==0) printf("%d %d\n",sum1-1,sum2+1);
			else printf("%d %d\n",sum1,sum2);
		}
	}
	else printf("Poor wyh\n");
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		fuck();
 return 0;
}

