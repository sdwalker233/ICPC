#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,t[2010];
const int mod 1000000007
long long dp[2010];

void fuck()
{
	int i,j,k,sum=0;
	long long mx=0;
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&t[i]);
		sum+=t[i];
	}
	dp[0]=1;
	for(i=1;i<=n;i++){
		for(j=sum;j>0;j--){
			for(k=1;k<=t[i]&&j>=k;k++){
				dp[j]+=dp[j-k];
			}
		}
	}
	for(i=1;i<=sum;i++)
		mx=max(dp[i],mx);
	printf("%lld\n",mx);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}


