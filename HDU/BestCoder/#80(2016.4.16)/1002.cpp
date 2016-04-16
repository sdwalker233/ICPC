#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long p;

inline long long mulmod(long long x, long long y, long long mod)
{
	long long ret = 0,tmp=x;
	while(y){
		if(y&1) ret=(ret+tmp)%mod;
		y>>=1;
		tmp=(tmp+tmp)%mod;
	}
	return ret;
}

int main()
{
	int t;
	long long q;
	scanf("%d",&t);
	while(t-->0){
		cin>>q>>p;
		long long a=q-1,b=q-2;
		if(a%2==0) a/=2;
		else b/=2;
		cout<<mulmod(a,b,p)<<endl;
	}
 return 0;
}

