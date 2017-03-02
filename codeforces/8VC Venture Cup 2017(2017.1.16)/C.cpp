#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;
int n,fa[MAXN];

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

int main()
{
	int n,i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		fa[find(x)]=find(i);
	}
	set<int> st;
	for(i=1;i<=n;i++){
		st.insert(find(i));
	}
	cout<<st.size()<<endl;
 return 0;
}

