#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 55
using namespace std;
int n,v[MAXN],m[MAXN];
bool dp[300000];

void fuck()
{
	int i,j,k,sum=0;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++){
		scanf("%d%d",&v[i],&m[i]);
		sum+=v[i]*m[i];
	}
	dp[0]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=m[i];j++){
			for(k=sum;k>=v[i];k--){
				if(dp[k-v[i]]) dp[k]=1;
			}
		}
	}
	for(i=(sum+1)/2;i<=sum;i++){
		if(dp[i]){
			printf("%d %d\n",i,sum-i);
			break;
		}
	}
}

int main()
{
	while(~scanf("%d",&n)&&n>=0)
		fuck();
 return 0;
}