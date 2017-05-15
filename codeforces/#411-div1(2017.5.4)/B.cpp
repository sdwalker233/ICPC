#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main()
{
	string s;
	cin>>s;
	long long ans=0,tmp=0;
	int num=0;
	reverse(s.begin(),s.end());
	for(auto c:s){
		if(c=='b') num++;
		else{
			ans=(ans+num)%mod;
			num=num*2%mod;
		}
	}
	cout<<ans<<endl;
 return 0;
}

