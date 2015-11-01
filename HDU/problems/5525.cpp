#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long mod=1000000007;
const long long phi=1000000006;
long long n,a[100010],b[100010];

long long q_pow(long long a,long long n,long long mod)
{
	long long tmp=1;
	while(n){
		if(n&1) tmp=(tmp*a)%mod;
		a=(a*a)%mod;
		n/=2;
	}
	return tmp;
}

void fuck()
{
	int i,j,v;
	long long pro=1,ans=1;
	bool flag=0;
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		v=i;
		for(j=2;j*j<=i;j++){
			if(v%j==0)
				while(v%j==0){
					b[j]+=a[i];
					v/=j;
				}
			}
		if(v>1) b[v]+=a[i];
	}
	for(i=1;i<=n;i++){
		if(!b[i]) continue;
		if(!flag&&b[i]%2){
			flag=true;
			pro=(pro*(b[i]+1)/2)%phi;
		}
		else pro=(pro*(b[i]+1))%phi;
	}
	for(i=1;i<=n;i++){
		if(!b[i]) continue;
		if(!flag) b[i]/=2;
		ans=(ans*q_pow(i,b[i]*pro%phi+phi,mod))%mod;
	}
	printf("%lld\n",ans);
}


int main()
{
	while(~scanf("%lld",&n))
		fuck();
 return 0;
}