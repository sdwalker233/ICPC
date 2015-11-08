#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
	long long int w,v;
}a[1010];
int n,m;
long long dp0[4010],dp1[4010],dp2[4010];

bool cmp(const node& x,const node& y)
{
	return x.w<y.w;
}

void fuck()
{
	int i,j;
	long long ans=0;
	memset(dp0,0,sizeof(dp0));
	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));
	scanf("%d%d",&n,&m);
	m*=2;
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].w,&a[i].v);
		a[i].w*=2;
	}
	sort(a+1,a+1+n,cmp);
	if(a[1].w/2>m){
		for(i=1;i<=n;i++) ans=max(ans,a[i].v);
		printf("%lld\n",ans);
		return;
	}
	for(i=1;i<=n;i++){
		for(j=m;j>=a[i].w/2;j--){
			if(j>=a[i].w) dp0[j]=max(dp0[j],dp0[j-a[i].w]+a[i].v);
			dp1[j]=max(dp1[j],dp0[j-a[i].w/2]+a[i].v);
			dp2[j]=max(dp2[j],dp1[j-a[i].w/2]+a[i].v);
		}
	}
	for(i=0;i<=m;i++){
		ans=max(ans,dp0[i]);
		ans=max(ans,dp1[i]);
		ans=max(ans,dp2[i]);
	}
	printf("%lld\n",ans);
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		fuck();
	}
 return 0;
}