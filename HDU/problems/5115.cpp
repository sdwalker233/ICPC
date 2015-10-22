#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[210],b[210],n;
int dp[210][210],last[210][210];
void fuck()
{
	int i,j,k,sum=0,x;
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		sum+=x;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	b[0]=b[n+1]=0;
	for(i=1;i<=n;i++)
		dp[i][i]=b[i-1]+b[i+1];
	for(i=1;i<n;i++){
		for(j=1;i+j<=n;j++){
			dp[j][i+j]=0x7fffffff;
			//dp[j][i+j]=min(dp[j+1][i+j]+b[j],dp[j][i+j-1]+b[i+j]);
			for(k=j;k<=i+j;k++){
				if(dp[j][k-1]+dp[k+1][i+j]+b[j-1]+b[i+j+1]<dp[j][i+j]){
					dp[j][i+j]=dp[j][k-1]+dp[k+1][i+j]+b[j-1]+b[i+j+1];
				}
			}
		}
	}
	printf("%d\n",dp[1][n]+sum);
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		fuck();
	}
 return 0;
}