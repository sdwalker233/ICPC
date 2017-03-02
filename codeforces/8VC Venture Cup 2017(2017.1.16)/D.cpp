#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n,k,p=1,x=1,ans=1;
	cin>>n>>k;
	k=min(k,n-k);
	for(int i=1;i<=n;i++){
		if(p<=n&&p+k>n+1){
			 x++;
			ans+=x;
			x++;
		}
		else ans+=x;
		p+=k;
		if(p>n) p-=n;
		cout<<ans<<" ";
	}
 return 0;
}

