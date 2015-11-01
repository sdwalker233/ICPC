#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#define INF 0xffffffffffffff
using namespace std;
struct node{
	long long dis;
	int index;
	node(int _index=0,long long _dis=0){
		dis=_dis;
		index=_index;
	}
	friend bool operator <(const node &a,const node &b){
		return a.dis>b.dis;
	}
};
int n,m,ans[100010];
long long a[100010],b[100010],t[100010];
set<int> s[100010];
set<int>::iterator it;
vector<int> v[100010];

void search(int x,long long dis[])
{
	priority_queue<node> q;
	bool vis_set[100010]={0},vis_node[100010]={0};
	int i,j,k,p;
	node now;
	for(i=1;i<=n;i++) dis[i]=INF;
	q.push(node(x,0));
	while(!q.empty()){
		do{
			now=q.top();
			q.pop();
		}while(vis_node[now.index]&&!q.empty());
		if(q.empty()&&vis_node[now.index]) return;
		p=now.index;
		dis[p]=now.dis;
		vis_node[p]=1;
		for(j=0;j<v[p].size();j++){
			i=v[p][j];
			if(vis_set[i]) continue;
			for(it=s[i].begin();it!=s[i].end();it++){
				if(!vis_node[*it]&&dis[*it]>dis[p]+t[i]){
					dis[*it]=dis[p]+t[i];
					if(v[*it].size()>1)
						q.push(node(*it,dis[*it]));
				}
			}
			vis_set[i]=1;
		}
	}
}

void fuck()
{
	int i,j,S,x,cnt=0;
	long long mn=INF;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) v[i].clear();
	for(i=1;i<=m;i++){
		s[i].clear();
		scanf("%lld%d",&t[i],&S);
		for(j=1;j<=S;j++){
			scanf("%d",&x);
			s[i].insert(x);
			v[x].push_back(i);
		}
	}
	search(1,a);
	search(n,b);
	for(i=1;i<=n;i++)
		mn=min(mn,max(a[i],b[i]));
	if(mn==INF){
		printf("Evil John\n");
		return;
	}
	printf("%lld\n",mn);
	for(i=1;i<=n;i++)
		if(max(a[i],b[i])==mn) ans[++cnt]=i;
	for(i=1;i<cnt;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[cnt]);
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		fuck();
	}
 return 0;
}