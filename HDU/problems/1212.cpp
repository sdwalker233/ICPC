#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	char s[100010];
	int mod;
	int ans,l,i;
	while(~scanf("%s%d",s,&mod)){
		ans=0;l=strlen(s);
		for(i=0;i<l;i++){
			ans=ans*10+s[i]-'0';
			ans%=mod;
		}
		cout<<ans<<endl;
	}
 return 0;
}

