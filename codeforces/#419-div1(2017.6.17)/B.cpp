#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
const int mod=1e9+7;
int n,a[MAXN];

long long q_pow(long long x,long long n)
{
	long long res=1,tmp=x;
	while(n){
		if(n&1) res=res*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return res;
}

int main()
{
	int i,j,c=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	while(n%4!=1){
		for(i=1;i<n;i++){
			if(c) a[i]=(a[i]+a[i+1])%mod;
			else a[i]=(a[i]-a[i+1]+mod)%mod;
			c^=1;
		}
		n--;
	}
	long long p=n/2,C=1,ans=0;
	for(i=0;i<=p;i++){
		if(i) C=C*(p-i+1)%mod*q_pow(i,mod-2)%mod;
		//cout<<C<<endl;
		ans+=C*a[i<<1|1];
		ans%=mod;
	}
	cout<<ans<<endl;
 return 0;
}

