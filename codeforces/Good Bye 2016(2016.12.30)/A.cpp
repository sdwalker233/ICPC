#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i,n,k;
	cin>>n>>k;
	k=240-k;
	int sum=0;
	for(i=1;i<=n;i++){
		sum+=5*i;
		if(sum>k) break;
	}
	cout<<i-1<<endl;
 return 0;
}

