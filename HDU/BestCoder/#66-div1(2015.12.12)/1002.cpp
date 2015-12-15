#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,x;

long long eular(long long n)
{
	long long ret=1,i;
	for(i=2; i*i<=n; i++) {
		if(n%i==0) {
			n/=i,ret*=i-1;
			while(n%i==0)
				n/=i,ret*=i;
		}
	}
	if(n>1)
		ret*=n-1;
	return ret;
}

int main()
{
	while(~scanf("%I64d%I64d",&n,&x))
		printf("%lld\n",eular(x+1+n));
	return 0;
}


