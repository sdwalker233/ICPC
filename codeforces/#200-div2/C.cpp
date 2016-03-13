#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	long long a,b,ans=0;
	scanf("%I64d%I64d",&a,&b);
	while(a&&b){
		if(a>b){
			ans+=a/b;
			a%=b;
		}
		else{
			ans+=b/a;
			b%=a;
		}
	}
	cout<<ans<<endl;
 return 0;
}