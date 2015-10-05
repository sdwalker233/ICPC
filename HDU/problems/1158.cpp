#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,h,s,f,a[20];
int dp[20][200];

void fuck()
{
	int i,j,k,mx=0,mn=0x7fffffff;
	memset(dp,0,sizeof(dp));
	scanf("%d%d%d",&h,&s,&f);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	}
	for(i=a[1];i<=mx;i++)
		dp[1][i]=(h+s)*i;
	for(i=2;i<=n;i++){
		for(j=a[i];j<=mx;j++){
			dp[i][j]=0x7fffffff;
			for(k=a[i-1];k<=mx;k++){
				if(k>=j) dp[i][j]=min(dp[i][j],dp[i-1][k]+s*j+(k-j)*f);
				else dp[i][j]=min(dp[i][j],dp[i-1][k]+s*j+(j-k)*h);
			}
		}
	}
	/*
	for(i=1;i<=n;i++){
		for(j=0;j<=mx;j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}
	*/
	for(i=a[n];i<=mx;i++)
		mn=min(mn,dp[n][i]);
	printf("%d\n",mn);
}

int main()
{
	while(~scanf("%d",&n)&&n)
		fuck();
}