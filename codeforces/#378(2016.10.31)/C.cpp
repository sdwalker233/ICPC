#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
map<pair<int,int>,int > mp[MAXN];
map<pair<int,int>,int >::iterator it;
int n;
int a[MAXN],b[MAXN],c[MAXN];
set<int> st;
map<int,int> li;
int fa[MAXN];

int mmin(int x,int y,int z)
{
	return min(min(x,y),z);
}

int f(int x,int y,int z)
{
	if(mp[x].empty()) return 0;
	it=mp[x].upper_bound(make_pair(y+1,0));
	it--;
	if(it==mp[x].begin()||(it->first).first!=y) return 0;
	//printf(" %d %d %d\n",x,y,z);
	//printf("  %d %d %d\n",(it->first).first,(it->first).second,it->second);
	return mmin(fa[x],fa[y],fa[z]+fa[(it->first).second]);
}

int main()
{
	int i,d[4];
	scanf("%d",&n);
	int ans,ansr=0;
	int m[5];
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		st.insert(a[i]);
		st.insert(b[i]);
		st.insert(c[i]);
	}
	int t=0;
	for(auto itt:st){
		++t;
		li[itt]=t;
		fa[t]=itt;
	}
	for(i=1;i<=n;i++){
		d[1]=li[a[i]];d[2]=li[b[i]];d[3]=li[c[i]];
		sort(d+1,d+4);
		if(fa[d[1]]>ansr){ansr=fa[d[1]];ans=1;m[1]=i;}
		int tmp=f(d[3],d[2],d[1]);
		if(tmp>ansr){ansr=tmp;ans=2;m[1]=it->second;m[2]=i;}
		mp[d[1]][make_pair(d[2],d[3])]=i;
		mp[d[1]][make_pair(d[3],d[2])]=i;
		mp[d[2]][make_pair(d[1],d[3])]=i;
		mp[d[2]][make_pair(d[3],d[1])]=i;
		mp[d[3]][make_pair(d[2],d[1])]=i;
		mp[d[3]][make_pair(d[1],d[2])]=i;
	}
	printf("%d\n",ans);
	for(i=1;i<=ans;i++) printf("%d ",m[i]);
 return 0;
}

