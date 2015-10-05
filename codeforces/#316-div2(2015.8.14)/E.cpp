#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int dp1[510][510],dp2[510][510];
char s[510][510];

int main()
{
	int n,m,i,j,k,y1,y2,sum=0,step;
	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));
	scanf("%d%d",&n,&m);
	step=(n+m-2)/2;
	for(i=1;i<=n;i++)
		scanf("%s",&s[i][1]);
	if(s[1][1]==s[n][m]) dp2[1][n]=1;
	else{
		printf("0\n");
		return 0;
	}
	for(k=1;k<=step;k++){
		for(i=1;i<=min(1+k,n);i++){
			y1=k+2-i;
			if(y1<1||y1>m) continue;
			for(j=n;j>=max(1,n-k);j--){
				y2=n+m-j-k;
				if(y2<1||y2>m) continue;
				if(s[i][y1]!=s[j][y2]) continue;
				if(y1>1&&y2<m) dp1[i][j]=(dp1[i][j]+dp2[i][j])%mod;
				if(i>1&&y2<m) dp1[i][j]=(dp1[i][j]+dp2[i-1][j])%mod;
				if(y1>1&&j<n) dp1[i][j]=(dp1[i][j]+dp2[i][j+1])%mod;
				if(i>1&&j<n) dp1[i][j]=(dp1[i][j]+dp2[i-1][j+1])%mod;
			}
		}
		memcpy(dp2,dp1,sizeof(dp1));
		memset(dp1,0,sizeof(dp1));
	}
	if((n+m)%2){
		for(i=1;i<=n;i++)
			sum=(sum+dp2[i][i])%mod;
		for(i=1;i<n;i++)
			sum=(sum+dp2[i][i+1])%mod;
	}
	else{
		for(i=1;i<=n;i++)
			sum=(sum+dp2[i][i])%mod;
	}
	printf("%d\n",sum);
	/*for(k=0;k<=step;k++){
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				printf(" %d %d %d %d\n",k,i,j,dp[k][i][j]);
		printf("\n");
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			printf(" %d %d %d\n",i,j,dp2[i][j]);
	*/
 return 0;
}


