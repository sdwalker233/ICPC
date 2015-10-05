#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long front[200010]={0},back[200010]={0};

int main()
{
	int n,k,x,i,j,l;
	long long a[200010],p[11];
	long long ans=0;
	scanf("%d%d%d",&n,&k,&x);
	for(i=1;i<=n;i++) scanf("%I64d",&a[i]);
	p[0]=1;
	for(i=1;i<=k;i++) p[i]=p[i-1]*x;
	for(i=1;i<=n;i++) front[i]=(front[i-1]|a[i]);
	for(i=n;i>=1;i--) back[i]=(back[i+1]|a[i]);
	for(i=1;i<=n;i++)
		ans=max(ans,front[i-1]|back[i+1]|(a[i]*p[k]));
	printf("%I64d\n",ans);
 return 0;
}

