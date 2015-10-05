#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10010
using namespace std;
const int mod=1000000007;
long long b1,q,a1,d,n,m;
long long C[MAXN],q1[MAXN],q2[MAXN],a[MAXN];

long long QP(long long a,long long n){
    long long tmp=a,ans=1;
    while(n){
        if(n&1)ans=ans*tmp%mod;
        tmp=tmp*tmp%mod;
        n>>=1;
    }
    return ans;
}

long long rev(long long a,long long m)
{
	return QP(a,m-2);
}

long long Qpow(long long a,long long b)
{
	return QP(a,(b+mod-1)%(mod-1));
}

void fuck()
{
	int i;
	long long ans=0;
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&b1,&q,&a1,&d,&n,&m);
	C[n]=1;
	for(i=n-1;i>=1;i--){
		C[i]=C[i+1]*(m+n-1-i)%mod*rev(n-i,mod)%mod;
		//printf(" %I64d\n",C[i]);
	}
	q1[0]=q2[0]=1;a[0]=a1-d;
	for(i=1;i<=n;i++){
		q1[i]=((q1[i-1]*(q-1)%mod)+mod)%mod;
		q2[i]=(q2[i-1]*q)%mod;
		a[i]=(a[i-1]+d)%mod;
	}
	ans+=b1*Qpow(q,m%(mod-1)+n-1)%mod;
	for(i=1;i<=n;i++){
		ans=(ans+
			((q1[n]*a[i])%mod-b1*q2[i-1]%mod*q1[n-i]%mod+mod)%mod*C[i]%mod
			)%mod;
	}
	long long r=rev(q-1,mod);
	for(i=1;i<=n;i++)
		ans=(ans*r)%mod;
	printf("%I64d\n",ans);
}

int main()
{
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		fuck();
	}
 return 0;
}