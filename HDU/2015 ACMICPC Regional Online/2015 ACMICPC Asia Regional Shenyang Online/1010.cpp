#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 201324
using namespace std;
const long long mod=530600414;
long long num[MAXN],g[MAXN],p[MAXN],q[MAXN],s[MAXN];
int r[MAXN];

int n;

int main()
{
	int t,i;
	num[1]=1;num[2]=0;
	for(i=3;i<=201314;i++) num[i]=(num[i-1]+num[i-2])%mod;
	for(i=1;i<=201314;i++)
		if(i%2==0) r[i]=3;
		else r[i]=5;
	g[5]=q[5]=p[5]=s[5]=5;
	g[6]=16;p[6]=13;q[6]=11;s[6]=8;
	for(i=7;i<=201314;i++){
		p[i]=(p[i-2]+p[i-1]+(num[i-2]*s[i-1])%mod+(num[i-2]*r[i])%mod)%mod;
		q[i]=(q[i-1]+q[i-2]+(num[i-1]*s[i-2])%mod+(num[i-1]*r[i])%mod)%mod;
		s[i]=(s[i-1]+s[i-2]+r[i])%mod;
		g[i]=(g[i-1]+g[i-2]+(p[i-2]*num[i-1])%mod+(q[i-1]*num[i-2])%mod+((r[i]*num[i-1])%mod*num[i-2])%mod)%mod;
	}
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&n);
		//printf("%I64d %I64d %I64d %I64d\n",g[n],p[n],q[n],num[n]);
		printf("Case #%I64d: %d\n",i,g[n]);
	}
 return 0;
}
