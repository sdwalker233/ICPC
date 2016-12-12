#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define fi first
#define se second
#define MAXN 1010
using namespace std;
typedef pair<int,int> PII;

int n,m;
int x[1010],sum0[1010],sum1[1010];
set<PII > st0,st1;
set<PII >::iterator it,it1;
map<int,int> mp0,mp1;

bool gao()
{
	int a,b;
	map<int,int>::iterator it;
	scanf("%d%d",&a,&b);
	it=mp0.lower_bound(a);
	if(it==mp0.end()||b<it->se) return 0;
	it=mp1.upper_bound(a);
	--it;
	if(b>it->se) return 0;
	return 1;
}

void fuck()
{
	int i,j,a,b,up;
	st0.clear();st1.clear();
	mp0.clear();mp1.clear();
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&x[i]);
		if(i&1) sum0[(i+1)/2]=sum0[i/2]+x[i];
		else sum1[i/2]=sum1[i/2-1]+x[i];
	}
	for(i=1;i<=(n+1)/2;i++){
		for(j=i;j<=(n+1)/2;j++){
			a=sum0[j]-sum0[i-1];
			b=sum1[j-1]-sum1[i-1];
			//printf("  %d %d\n",a,b);
			st0.insert(PII(a,b));
		}
	}
	for(i=1;i<=n/2;i++){
		for(j=i;j<=n/2;j++){
			a=sum0[j]-sum0[i];
			b=sum1[j]-sum1[i-1];
			st1.insert(PII(a,b));
		}
	}
	for(it=st0.begin();it!=st0.end();++it){
		++it;it1=it;--it;
		if(it1==st0.end()) break;
		if(it->fi==it1->fi){
			st0.erase(it1);
			--it;
		}
		else if(it->se>=it1->se){
			st1.erase(it);
			it=it1;
			--it;
		}
	}
	for(it=st1.begin();it!=st1.end();++it){
		++it;it1=it;--it;
		if(it1==st1.end()) break;
		if(it->fi==it1->fi){
			st1.erase(it);
			it=it1;
			--it;
			continue;
		}
		if(it==st1.begin()) continue;
		--it;it1=it;++it;
		if(it->se<=it1->se){
			st1.erase(it);
			it=it1;
			--it;
		}
	}
	for(it=st0.begin();it!=st0.end();++it)
		mp0[it->fi]=it->se;
	for(it=st1.begin();it!=st1.end();++it)
		mp1[it->fi]=it->se;
	/*for(it=mp0.begin();it!=mp0.end();++it){
		printf(" %d %d\n",it->first,it->second);
	}
	for(it=mp1.begin();it!=mp1.end();++it){
		printf("  %d %d\n",it->first,it->second);
	}*/
	while(m-->0){
		if(gao()) putchar('1');
		else putchar('0');
	}
	puts("");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

