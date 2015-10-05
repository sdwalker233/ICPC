#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int a[80],b[80],c[80],d[80],l[80],n[80];
long long ans[80],dis[80][80];

void fuck()
{
	int i,j;
	set<int> t[80];
	set<int>::iterator it;
	for(i=1;i<=m;i++)
		scanf("%d%d%d%d%d",&a[i],&b[i],&c[i],&d[i],&l[i]);
	n[0]=1;ans[0]=0;
	for(i=1;i<=m;i++){
		n[i]=n[a[i]]+n[b[i]];
		t[a[i]].insert(c[i]);
		t[b[i]].insert(d[i]);
	}
	for(i=m-1;i>1;i--){
		for(it=t[i].begin();it!=t[i].end();it++){
			if(*it<n[a[i]]) t[a[i]].insert(*it);
			else t[b[i]].insert(*it-n[a[i]]);
		}
	}
	for(i=1;i<=m;i++){
		ans[i]=((dis[a[i]][c[i]]*n[b[i]])%mod+(dis[b[i]][d[i]]*n[a[i]])%mod+((n[a[i]]*n[b[i]])%mod*l[i])%mod)%mod;
		for(it=t[i].begin();it!=t[i].end();it++){
			if(*it<n[a[i]]) dis[i][*it]=
		}
	}
}
int main()
{
	while(~scanf("%d",&m))
		fuck();
 return 0;
}

