#include <bits/stdc++.h>
#define MAXN 300010
using namespace std;
struct E{
	int to,next;
}edge[MAXN<<1];
int head[MAXN],tot=0;
int n,m,ans=1,d[MAXN];
vector<int> a[MAXN];
int s[MAXN],col[MAXN]={0};
int mx=0;

void addedge(int x,int y)
{
	++tot;
	edge[tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

void DFS(int x,int pre)
{
	//printf(" %d %d\n",x,pre);
	int i;
	set<int> S;
	for(i=0;i<a[x].size();i++){
		S.insert(col[a[x][i]]);
	}
	S.insert(0);
	S.insert(m+1);
	for(i=0;i<a[x].size();i++){
		int it=a[x][i];
		if(col[it]==0){
			auto it1=S.begin();
			while(1){
				it1=S.begin();
				it1++;
				auto it2=it1;
				it1--;
				if(*it1+1==*it2) S.erase(*it1);
				else break;
			}
			col[it]=*it1+1;
			S.erase(it1);
			S.insert(col[it]);
		}
	}
/*
	for(auto it:a[pre]){
		if(a[x].find(it)==a[x].end()){
			st.insert(col[it]);
		}
	}
	for(auto it:a[x]){
		if(a[pre].find(it)==a[pre].end()){
			if(col[it]==0){
				auto itt=st.begin();
				col[it]=*itt;
				d[it]=x;
				st.erase(itt);
				ans=max(ans,col[it]);
			}
			else st.erase(col[it]);
		}
	}
*/
	for(i=head[x];~i;i=edge[i].next){
		if(edge[i].to==pre) continue;
		DFS(edge[i].to,x);
	}
/*
	for(auto it:a[x]){
		if(d[it]==x&&a[pre].find(it)==a[pre].end()){
			st.erase(col[it]);
		}
	}
	for(auto it:a[pre]){
		if(a[x].find(it)==a[x].end()){
			st.insert(col[it]);
		}
	}
*/
}

int main()
{
	int i,j,x,y,p=1;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&s[i]);
		if(s[i]>s[p]) p=i;
		for(j=1;j<=s[i];j++){
			scanf("%d",&x);
			a[i].push_back(x);
		}
	}
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	DFS(p,0);
	for(i=1;i<=m;i++){
		if(col[i]==0) col[i]=1;
		ans=max(ans,col[i]);
	}
	printf("%d\n",ans);
	for(i=1;i<=m;i++) printf("%d ",col[i]);
 return 0;
}

