#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
using namespace std;
const int mod=1000000007;
int n;
bool is_prime[MAXN];

long long quick_pow(long long a,long long n,long long mod)
{
	long long ans=1;
	while(n){
		if(n&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return ans;
}

void fuck()
{
	long long i,j;
	long long ans=1;
	memset(is_prime,0,sizeof(is_prime));
	scanf("%d",&n);
	n++;
	for(i=2;i<=n;i++){
		if(!is_prime[i]){
			for(j=i;j<=n;j+=i)
				is_prime[j]=1;
			for(j=i;j<=n;j*=i)
				ans=(ans*i)%mod;
		}
	}
	ans=(ans*quick_pow(n,mod-2,mod))%mod;
	printf("%lld\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}