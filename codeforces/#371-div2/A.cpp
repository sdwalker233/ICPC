#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long l1,l2,r1,r2,k,ans=0;
	cin>>l1>>r1>>l2>>r2>>k;
	long long l=max(l1,l2),r=min(r1,r2);
	ans=(r>=l)?r-l+1:0;
	if(k<=r&&k>=l) ans--;
	cout<<ans<<endl;
 return 0;
}

