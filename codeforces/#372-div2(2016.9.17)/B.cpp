#include <bits/stdc++.h>
#define MAXN 1010
#define MAXM 10010
using namespace std;
int tot,head[MAXN];
int n,m,s,t,l;
long long g[1010][1010],g2[1010][1010];
long long dis1[MAXN],dis2[MAXN];
int pre1[MAXN],pre2[MAXN];
vector<pair<int,int> > e1,e2;

void dijkstra(int s,long long dis[],int pre[])
{
	int i,j,mnj;
	long long mn;
	bool vis[MAXN]={0};
	for(i=0;i<n;i++){
		dis[i]=g[s][i];
		pre[i]=s;
	}
	dis[s]=pre[s]=0;vis[s]=1;
	for(i=1;i<n;i++){
		mn=0x3fffffffffffffff;
		for(j=0;j<n;j++){
			if(!vis[j]&&dis[j]<mn){
				mn=dis[j];
				mnj=j;
			}
		}
		vis[mnj]=1;
		for(j=0;j<n;j++){
			if(vis[j]) continue;
			if(dis[mnj]+g[mnj][j]<dis[j]){
				dis[j]=dis[mnj]+g[mnj][j];
				pre[j]=mnj;
			}
		}
	}
}

int main()
{
	int i,x,y,v;
	cin>>n>>m>>l>>s>>t;
	memset(g,0x3f,sizeof(g));
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&v);
		g[x][y]=g[y][x]=v;
		e1.push_back(make_pair(x,y));
		if(v==0){
			e2.push_back(make_pair(x,y));
			g2[x][y]=g2[y][x]=1;
		}
		//addedge(x,y,v);
		//addedge(y,x,v);
	}
	for(auto it:e2){
		g[it.first][it.second]=g[it.second][it.first]=0x3fffffff;
	}
	dijkstra(s,dis1,pre1);
	if(dis1[t]<l){
		printf("NO\n");
		return 0;
	}
	else if(dis1[t]==l){
		printf("YES\n");
		for(auto it:e1){
			x=it.first;y=it.second;
			printf("%d %d ",x,y);
			if(g2[x][y]==0) cout<<g[x][y]<<endl;
			else cout<<10000000000ll<<endl;
		}
		return 0;
	}
	for(auto it:e2){
		g[it.first][it.second]=g[it.second][it.first]=1;
	}
	if(dis2[t]>l){
		printf("NO\n");
		return 0;
	}
	dijkstra(s,dis2,pre2);
	int p=t,f=0;
	//printf(" %d\n",dis2[t]);
	while(p!=s){
		//printf(" %d\n",p);
		if(g2[p][pre2[p]]){
			if(f==0){
				g[p][pre2[p]]=g[pre2[p]][p]=g[pre2[p]][p]+l-dis2[t];
				f=1;
			}
			g2[p][pre2[p]]++;
			g2[pre2[p]][p]++;
		}
		p=pre2[p];
	}
	if(f==0&&dis2[t]!=l){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(auto it:e1){
		x=it.first;y=it.second;
		printf("%d %d ",x,y);
		if(g2[x][y]==0) cout<<g[x][y]<<endl;
		else if(g2[x][y]==1) cout<<10000000000ll<<endl;
		else cout<<g[x][y]<<endl;
	}
 return 0;
}

