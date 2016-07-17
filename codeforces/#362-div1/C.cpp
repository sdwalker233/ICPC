#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

long long qpow(long long a,long long n)
{
	long long res=1,tmp=a;
	while(n){
		if(n&1) res=res*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return res;
}

int main()
{
	int n,i,k;
	long long p3=qpow(3,mod-2),p2=qpow(2,mod-2);
	long long a,x=1,y=2;
	bool f=0;
	scanf("%d",&k);
	for(i=1;i<=k;i++){
		cin>>a;
		if(a%2==0) f=1;
		y=qpow(y,a);
	}
	y=y*p2%mod;
	if(f) x=y+1;
	else x=(y-1+mod)%mod;
	x=x*p3%mod;
	cout<<x<<"/"<<y<<endl;
 return 0;
}

