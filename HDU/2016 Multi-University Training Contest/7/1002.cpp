#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	long long n,m,a,b,g;
	while(~scanf("%lld%lld",&n,&m)&&(n||m)){
		a=n*(m-1);
		b=m*m;
		g=gcd(a,b);
		printf("%lld/%lld\n",a/g,b/g);
	}
 return 0;
}

