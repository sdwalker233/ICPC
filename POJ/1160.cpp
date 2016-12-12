#include <bits/stdc++.h>
#define MAXN 305
using namespace std;
int n,p;
int a[MAXN];
int dp[MAXN][MAXN],d[MAXN][MAXN],s[MAXN][MAXN],w[MAXN][MAXN],sumd[MAXN][MAXN];

int main()
{
	int i,j,k;
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			d[i][j]=d[j][i]=a[j]-a[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			sum[i][j]=sum[i][j-1]+d[i][j];
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			w[i][j]=sum[(i+j)/2][j]-sum[(i+j)/2][i-1];
	for(i=1;i<=n;i++)
 return 0;
}

