#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long n;

void fuck()
{
	int i,cnt=0,deep=0,mx=0;
	bool ok=0;
	long long fa;
	while(n){
		deep++;
		fa=(n>>1);
		if(!ok&&fa*2==n){
			ok=1;
			mx=max(mx,deep);
		}
		if(ok) cnt++;
		if(fa*2==n)	mx=max(mx,deep-1);
		else if(fa) mx=max(mx,deep);
		//printf("%d %d\n",n,mx);
		n=fa;
	}
	if(cnt==0) printf("%d\n",deep);
	else printf("%d\n",cnt-1+mx);
}

int main()
{
	while(~scanf("%lld",&n))
		fuck();	
 return 0;
}