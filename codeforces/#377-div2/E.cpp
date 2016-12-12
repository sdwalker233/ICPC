#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
int n,m;
int p[MAXN];
struct node{
	int v,in;
}s[MAXN];
int pp[MAXN],ss[MAXN];
set<pair<int,int> > st;
set<pair<int,int> >::iterator it;

bool cmp1(const node &x, const node &y)
{
	return x.v<y.v;
}

bool cmp2(const node &x, const node &y)
{
	return x.in<y.in;
}

int main()
{
	int i,j,c=0,u=0;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%d",&p[i]);
		st.insert(make_pair(p[i],i));
	}
	for(i=1;i<=m;i++){
		scanf("%d",&s[i].v);
		s[i].in=i;
	}
	sort(s+1,s+m+1,cmp1);
	for(i=1;i<=m;i++){
		int t=0;
		while(1){
			//printf(" %d\n",s[i].v);
			it=st.lower_bound(make_pair(s[i].v,0));
			if(it!=st.end()&&it->first==s[i].v){
				//printf(" >>%d %d\n",it->first,it->second);
				c++;u+=t;
				ss[s[i].in]=t;
				pp[it->second]=s[i].in;
				st.erase(it);
				break;
			}
			if(s[i].v==1) break;
			s[i].v=(s[i].v+1)/2;
			t++;
		}
		//puts("");
	}
	sort(s+1,s+m+1,cmp2);
	printf("%d %d\n",c,u);
	for(i=1;i<=m;i++) printf("%d ",ss[i]);
	puts("");
	for(i=1;i<=n;i++) printf("%d ",pp[i]);
 return 0;
}

