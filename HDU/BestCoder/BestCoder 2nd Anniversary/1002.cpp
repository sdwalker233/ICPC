#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;
const int mod=998244353;
int n,b[MAXN],c[MAXN];

void fuck()
{
	int i,res=0;
	long long ans=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(c[1]!=b[1]) ans=0;
	else ans=1;
	for(i=2;i<=n;i++){
		if(c[i]<b[i]||b[i]>b[i-1]||c[i]<c[i-1]){
			ans=0;
		}
		else if(b[i]<b[i-1]&&c[i]>c[i-1]){
			ans=0;
		}
		else if(b[i]==b[i-1]&&c[i]==c[i-1]){
			ans=ans*res%mod;
			res--;
		}
		else if(b[i]<b[i-1]&&c[i]==c[i-1]){
			res+=b[i-1]-b[i];
			res--;
		}
		else if(b[i]==b[i-1]&&c[i]>c[i-1]){
			res+=c[i]-c[i-1];
			res--;
		}
	}
	cout<<ans<<endl;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0){
		fuck();
	}
 return 0;
}

