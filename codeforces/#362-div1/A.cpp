#include <bits/stdc++.h>
using namespace std;
map<long long,long long> mp;

void f1(long long v,long long u,long long w)
{
	if(v==u) return;
	if(v>u) swap(v,u);
	if(u/2<v){
		mp[v]+=w;
		mp[u]+=w;
		f1(v>>1,u>>1,w);
	}
	else{
		mp[u]+=w;
		f1(v,u>>1,w);
	}
}

long long f2(long long v,long long u)
{
	if(v==u) return 0;
	if(v>u) swap(v,u);
	if(u/2<v){
		return mp[v]+mp[u]+f2(v>>1,u>>1);
	}
	else{
		return mp[u]+f2(v,u>>1);
	}
}

int main()
{
	long long q,t,v,u,w;
	scanf("%d",&q);
	while(q-->0){
		cin>>t>>v>>u;
		if(t==1){
			cin>>w;
			f1(v,u,w);
		}
		else{
			cout<<f2(v,u)<<endl;
		}
	}
 return 0;
}

