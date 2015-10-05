#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[100010][11],dp[100010][11];

void fuck()
{
	int i,j,t,x,ans=0;
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&t);
		a[t][x]++;
	}
	a[1][0]=a[1][1]=a[1][2]=a[1][3]=a[1][7]=a[1][8]=a[1][9]=a[1][10]=0;
	a[2][0]=a[2][1]=a[2][2]=a[2][8]=a[2][9]=a[2][10]=0;
	a[3][0]=a[3][1]=a[3][9]=a[3][10]=0;
	a[4][0]=a[4][10]=0;
	for(i=1;i<=100000;i++)
		for(j=0;j<=10;j++){
			dp[i][j]=dp[i-1][j];
			if(j>0) dp[i][j]=max(dp[i-1][j-1],dp[i][j]);
			if(j<10) dp[i][j]=max(dp[i-1][j+1],dp[i][j]);
			dp[i][j]+=a[i][j];
		}
	for(i=0;i<=10;i++)
		ans=max(ans,dp[100000][i]);
	printf("%d\n",ans);
}

int main()
{
	while(~scanf("%d",&n)&&n)
		fuck();
 return 0;
}

