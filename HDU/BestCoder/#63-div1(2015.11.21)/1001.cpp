#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int n,m,a[110];
int dp[110][110];
map<int,bool> mp;

void fuck()
{
	int i,j,k;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[i][1]=1;
	}
	for(i=1;i<=n;i++){
		mp.clear();
		for(j=i-1;j>=1;j--){
			if(a[j]<a[i]){
				if(mp[a[j]]==1) continue;;
				for(k=1;k<=j;k++)
					dp[i][k+1]+=dp[j][k];
			}
			mp[a[j]]=1;
		}
	}
	long long sum=0;
	for(i=1;i<=n;i++){
		sum+=dp[i][m];
	}
	printf("%lld\n",sum);
}

int main()
{
	while(~scanf("%d%d",&n,&m))
		fuck();
 return 0;
}