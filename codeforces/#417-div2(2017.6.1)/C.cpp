#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int n;
long long m,a[MAXN],b[MAXN];

long long check(int k)
{
	memcpy(b,a,sizeof(a));
	for(int i=0;i<n;i++) b[i]=a[i]+(i+1ll)*k;
	nth_element(b,b+k,b+n);
	return accumulate(b,b+k,0ll);
}

int main()
{
	int i;
	cin>>n>>m;
	int L=0,R=n,ans=0;
	long long ans2=0;
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	while(L<=R){
		int mid=(L+R)>>1;
		long long tmp=check(mid);
		if(tmp<=m){
			L=mid+1;
			ans=max(ans,mid);
			ans2=tmp;
		}
		else R=mid-1;
	}
	cout<<ans<<" "<<ans2<<endl;
 return 0;
}

