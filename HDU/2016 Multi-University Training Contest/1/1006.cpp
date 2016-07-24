#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 10000010
using namespace std;
const int mod = 1000000007;
bool not_prime[MAXN];
int tot=0,prime[MAXN],phi[MAXN];
long long sum[MAXN];
int n,m,p;

long long qpow(long long a,long long n,long long mod)
{
	long long tmp=a,res=1;
	while(n){
		if(n&1) res=res*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return res;
}

long long cal(int n,int m)
{
	//printf(" %lld %lld\n",n,m);
	if(m==0) return 0;
	if(n==1) return sum[m];
	if(m==1) return phi[n];
	int i;
	for(i=1;i<=tot;i++)
		if(n%prime[i]==0)
			return ((prime[i]-1)*cal(n/prime[i],m)%mod+cal(n,m/prime[i]))%mod;
	return 0;
}

long long gao(long long k,int p)
{
	if(p==1) return 0;
	return qpow(k,phi[p]+gao(k,phi[p]),p);
}

void fuck()
{
	long long k=cal(n,m);
	//printf(" k=%lld\n",k);
	printf("%lld\n",gao(k,p));
}

void init()
{
	int i,j;
	phi[1]=1;
	for(i=2;i<=10000000;i++){
		if(!not_prime[i]){
			phi[i]=i-1;
			prime[++tot]=i;
		}
		for(j=1;j<=tot&&i*prime[j]<=10000000;j++){
			not_prime[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			else{
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}
		}
	}
	for(i=1;i<=10000000;i++) sum[i]=(sum[i-1]+phi[i])%mod;
}

int main()
{
	init();
	while(~scanf("%d%d%d",&n,&m,&p)) fuck();
 return 0;
}

