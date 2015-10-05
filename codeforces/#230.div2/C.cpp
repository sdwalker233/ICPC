#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,i,last,p;
	long long sum=0;
	cin>>n;
	if(n==0){
		cout<<"1";
		return 0;
	}
	last=sum=n;
	for(i=1;i<=n;i++){
		p=(long long)sqrt((double)n*n-i*i);
		if(last>p) sum+=last-p-1;
		last=p;
	}
	cout<<sum*4;
 return 0;
}

