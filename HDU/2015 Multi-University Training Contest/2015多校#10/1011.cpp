#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define vMAX 131072
#define nMAX 100010
using namespace std;
struct node{
	int v,to,next;
}edge[nMAX<<1];
int n,head[nMAX],tot,fa[nMAX],val[nMAX],num[vMAX+10];

inline void addedge(int x,int y,int v)
{
	++tot;
	edge[tot].v=v;
	edge[tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

void DFS(int x,int pre)
{
	int i;
	for(i=head[x];i!=-1;i=edge[i].next){
		if(edge[i].to!=pre){
			val[edge[i].to]=(val[x]^edge[i].v);
			DFS(edge[i].to,x);
		}
	}
}

void fuck()
{
	int i,x,y,v;
	memset(head,-1,sizeof(head));
	memset(val,0,sizeof(val));
	memset(num,0,sizeof(num));
	tot=0;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&v);
		addedge(x,y,v);
		addedge(y,x,v);
	}
	DFS(1,0);
	for(i=1;i<=n;i++)
		num[val[i]]++;
	int q,s,p;
	long long ans;
	scanf("%d",&q);
	while(q-->0){
		ans=0;
		scanf("%d",&s);
		for(i=0;i<=vMAX;i++){
			p=(s^i);
			if(num[i]&&num[p])
				if(i!=p) ans+=(long long)num[i]*num[p];
				else ans+=(long long)num[i]*(num[i]+1);
		}
		printf("%lld\n",ans/2);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0){
		fuck();
	}
 return 0;
}

