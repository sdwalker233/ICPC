#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define MAXN 1010
using namespace std;
int n,x[MAXN],y[MAXN];
map<pair<int,int>,int> mp;

void fuck()
{
	int i,j;
	mp.clear();
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(i=1;i<=n;i++){
		int cnt=0;
		for(j=1;j<=n;j++){
			if(i!=j&&x[i]==x[j]&&y[i]==y[j]) ++cnt;
		}
		for(j=1;j<=n;j++){
			if(x[i]==x[j]&&y[i]==y[j]) continue;
			int dx=abs(x[i]-x[j]),dy=abs(y[i]-y[j]);
			int g=__gcd(dx,dy);
			mp[make_pair(dx/g,dy/g)]++;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

