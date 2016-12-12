#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int n,m;
long long a[MAXN],b[MAXN];

bool check(long long int r)
{
	int i,c[MAXN]={0},st,ed;
	for(i=1;i<=m;i++){
		st=lower_bound(a+1,a+n+1,b[i]-r)-a;
		ed=upper_bound(a+1,a+n+1,b[i]+r)-a-1;
		//printf(" %d %d\n",st,ed);
		if(ed<st) continue;
		c[st]++;c[ed+1]--;
	}
	int v=0;
	for(i=1;i<=n;i++){
		v+=c[i];
		if(v<=0) return 0;
	}
	return 1;
}

int main()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for(i=1;i<=m;i++) scanf("%I64d",&b[i]);
	long long left=0,right=2000000010,mid,ans=2000000000;
	while(left<=right){
		mid=(left+right)>>1;
		if(check(mid)){
			right=mid-1;
			ans=min(ans,mid);
		}
		else left=mid+1;
	}
	//cout<<check(ans)<<endl;
	cout<<ans<<endl;
 return 0;
}

