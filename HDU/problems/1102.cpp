#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int a,b,v;
	bool operator<(node x)const{
		return v<x.v;
	}
}edge[10001];
int n,q,g[110][110],tot,num,fa[110];
bool visit[110][110];

 void init()
 {
 	memset(visit,0,sizeof(visit));
 	tot=num=0;
 	for(int i=1;i<=n;i++) fa[i]=i;
 }

 void addedge(int x,int y,int v)
 {
 	++tot;
 	edge[tot].a=x;
 	edge[tot].b=y;
 	edge[tot].v=v;
 }

 int find(int x)
 {
 	if(fa[x]==x) return x;
 	return fa[x]=find(fa[x]);
 }

 void unio(int x,int y)
 {
 	fa[x]=y;
 }

 int kruscal()
 {
 	int ans=0,i,f1,f2;
 	sort(edge+1,edge+tot+1);
 	for(i=1;i<=tot&&num<n-1;i++){
 		//printf(" %d %d %d\n",edge[i].a,edge[i].b,edge[i].v);
 		f1=find(edge[i].a);
		f2=find(edge[i].b);
 		if(f1!=f2){
 			unio(f1,f2);
 			num++;
 			ans+=edge[i].v;
 		}
 	}
 	return ans;
 }

int main()
{
	int i,j,f1,f2,a,b;
	while(~scanf("%d",&n)){
		init();
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&g[i][j]);
		scanf("%d",&q);
		for(i=1;i<=q;i++){
			scanf("%d%d",&a,&b);
			f1=find(a);f2=find(b);
			if(f1!=f2){
				unio(f1,f2);
				num++;
			}
			visit[a][b]=visit[b][a]=1;
		}
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(!visit[i][j]) addedge(i,j,g[i][j]);
		printf("%d\n",kruscal());
	}
 return 0;
}

