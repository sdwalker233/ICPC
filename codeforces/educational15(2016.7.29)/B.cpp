#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int n;
long long a[MAXN];
map<long long,int> mp;

int main()
{
	int i,j;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(j=1;j<=32;j++){
			long long p=(1ll<<j);
			if(p<=a[i]) continue;
			ans+=mp[p-a[i]];
		}
		mp[a[i]]++;
	}
	cout<<ans<<endl;
 return 0;
}

