#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
int n,a[MAXN<<1],b[MAXN]={0};

int main()
{
	int i,mn=0x7fffffff,mx=0;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mn=min(mn,a[i]);
	}
	ans=(long long)n*mn;
	for(i=1;i<=n;i++){
		a[i]-=mn;
		a[i+n]=a[i];
	}
	for(i=1;i<=n*2;i++){
		if(a[i]) b[i]=b[i-1]+1;
		else b[i]=0;
		mx=max(b[i],mx);
	}
	cout<<ans+min(mx,n)<<endl;
 return 0;
}