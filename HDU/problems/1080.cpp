#include<iostream>
#include<cstdio>
using namespace std;
int v[5][5]={5,-1,-2,-1,-3,
			 -1,5,-3,-2,-4,
			 -2,-3,5,-2,-2,
			 -1,-2,-2,5,-1,
			 -3,-4,-2,-1,0};

 void run()
 {
 	char s1[110],s2[110];
	int l1,l2,a[110],b[110],i,j,dp[110][110]={0};
	scanf("%d%s%d%s",&l1,s1+1,&l2,s2+1);
	for(i=1;i<=l1;i++)
		switch(s1[i]){
			case('A'):a[i]=0;break;
			case('C'):a[i]=1;break;
			case('G'):a[i]=2;break;
			case('T'):a[i]=3;break;
		}
	for(i=1;i<=l2;i++)
		switch(s2[i]){
			case('A'):b[i]=0;break;
			case('C'):b[i]=1;break;
			case('G'):b[i]=2;break;
			case('T'):b[i]=3;break;
		}

	for(i=1;i<=l2;i++)
		dp[0][i]=dp[0][i-1]+v[4][b[i]];
	for(i=1;i<=l1;i++)
		dp[i][0]=dp[i-1][0]+v[a[i]][4];

	for(i=1;i<=l1;i++)
		for(j=1;j<=l2;j++)
			dp[i][j]=max(dp[i-1][j-1]+v[a[i]][b[j]],max(dp[i][j-1]+v[4][b[j]],dp[i-1][j]+v[a[i]][4]));
	printf("%d\n",dp[l1][l2]);
 }

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		run();
 return 0;
}

