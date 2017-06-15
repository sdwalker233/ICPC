#include <bits/stdc++.h>
using namespace std;
int a[110][110];
int mx[110],mn[110];
int dp[20][2];

int main()
{
	int n,m,i,j;
	cin>>n>>m;
	for(i=n;i>=1;i--){
		mx[i]=0;mn[i]=m+1;
		for(j=0;j<=m+1;j++)
			scanf("%1d",&a[i][j]);
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i][j]){
				mx[i]=max(mx[i],j);
				mn[i]=min(mn[i],j);
			}
	dp[1][0]=2*mx[1];
	dp[1][1]=m+1;
	while(n>0){
		if(mx[n]==0) n--;
		else break;
	}
	if(n==0){
		printf("0\n");
		return 0;
	}
	if(n==1){
		printf("%d\n",mx[1]);
		return 0;
	}
		//printf(" %d %d\n",dp[1][0],dp[1][1]);
	for(i=2;i<=n;i++){
		if(mx[i]!=0){
			dp[i][0]=min(dp[i-1][0]+2*mx[i],dp[i-1][1]+m+1)+1;
			dp[i][1]=min(dp[i-1][1]+2*(m-mn[i]+1),dp[i-1][0]+m+1)+1;
		}
		else{
			dp[i][0]=dp[i-1][0]+1;
			dp[i][1]=dp[i-1][1]+1;
		}
		//printf(" %d %d\n",dp[i][0],dp[i][1]);
	}
	printf("%d\n",min(dp[n-1][0]+mx[n],dp[n-1][1]+(m+1-mn[n]))+1);
 return 0;
}

