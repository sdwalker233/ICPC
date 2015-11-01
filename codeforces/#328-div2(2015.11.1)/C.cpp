#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	long long t,a,b,c,l,r,g,p;
	cin>>t>>a>>b;
	if(a>b) swap(a,b);
	g=gcd(a,b);
	if(b/g>(double)t/a+1e-8){
		c=min(a-1,t);
	}
	else{
		l=a/g*b;
		r=t%l;
		c=t/l*a-1;
		c+=min(r+1,a);
	}
	if(c==0){
		printf("0/1\n");
		return 0;
	}
	g=gcd(c,t);
	cout<<c/g<<"/"<<t/g<<endl;
 return 0;
}