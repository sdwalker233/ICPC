#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long d,k,a,b,t,ans,n,m,tmp1,tmp2;
	cin>>d>>k>>a>>b>>t;
	m=d%k;
	n=d/k;
	if(k*a-k*b+t>=0){
		tmp1=n*k*b+m*b;
		tmp2=k*a-k*b+n*k*b+m*b;
	}
	else{
		tmp1=n*k*a+n*t+m*b-t;
		tmp2=n*k*a+n*t+m*a;
	}
	cout<<min(tmp1,tmp2)<<endl;
 return 0;
}

