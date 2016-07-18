#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
long long n,l,r,a[100010];
map<long long,int> mp;
map<long long,int>::iterator it;

void fuck()
{
	int i;
	long long ans=0;
	mp.clear();
	cin>>n>>l>>r;
	for(i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	mp[0]--;
	mp[l]++;
	mp[r+1]--;
	for(i=2;i<=n;i++){
		mp[a[i]-a[i-1]+1]--;
		mp[a[i]+a[i-1]]++;
	}
	int v=0;
	long long last=0;
	for(it=mp.begin();it!=mp.end();++it){
		if(v==0) ans+=(*it).first-last;
		last=(*it).first;
		v+=(*it).second;
	}
	cout<<ans<<endl;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

