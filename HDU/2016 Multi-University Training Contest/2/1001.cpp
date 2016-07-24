#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void fuck()
{
	int i,n;
	long long s1=0,s2=0,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&x);
		if(x<0) x=-x;
		s1+=x*x;
		s2+=x;
	}
	long long p=n*s1-s2*s2;
	if(p<0) p=-p;
	long long g=__gcd(p,(long long)n);
	printf("%lld/%lld\n",p/g,n/g);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

