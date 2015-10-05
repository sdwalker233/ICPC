#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,k,p,t[5][5],n;
	long long dp[50][5][5]={0};
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			scanf("%d",&t[i][j]);
	scanf("%d",&n);
	for(p=1;p<=n;p++){
		for(i=1;i<=3;i++){
			for(j=1;j<=3;j++){
				if(i==j) continue;
				k=6-i-j;
				dp[p][i][j]=min(2*dp[p-1][i][j]+dp[p-1][j][i]+t[i][k]+t[k][j],dp[p-1][i][k]+dp[p-1][k][j]+t[i][j]);
			}
		}
	}
	cout<<dp[n][1][3];
 return 0;
}

