#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[5011][5011]={0};

int main()
{
	int n,k,a[300010],i,j,x,y,p,sum;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	sum=a[n]-a[1];
	for(i=1;i<n;i++)
		a[i]=a[i+1]-a[i];
	x=n%k;
	y=k-x;
	p=n/k;
	for(i=0;i<=x;i++){
		for(j=0;j<=y;j++){
			if(i) dp[i][j]=max(dp[i][j],dp[i-1][j]+a[(i-1)*(p+1)+j*p]);
			if(j) dp[i][j]=max(dp[i][j],dp[i][j-1]+a[i*(p+1)+(j-1)*p]);
		}
	}
	//printf("%d %d %d\n",p,x,y);
	printf("%d\n",sum-dp[x][y]);
 return 0;
}


