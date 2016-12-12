#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=1e9+7;
int n,m;

long long qpow(long long a,long long n)
{
	long long tmp=a;
	long long res=1;
	while(n){
		if(n&1) res=res*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return res;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0){
		scanf("%d%d",&n,&m);
		long long ans=qpow(m,n+1);
		ans=(ans-1+mod)%mod;
		ans=ans*qpow(m-1,mod-2)%mod;
		cout<<ans<<endl;
	}
 return 0;
}

