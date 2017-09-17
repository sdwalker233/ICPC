#include <bits/stdc++.h>
#define MAXN 35010
using namespace std;
int n,k;
int a[MAXN],pre[MAXN],p[MAXN],u[MAXN];
int dp[MAXN][55],r[MAXN][55];

int main()
{
	int i,j,l;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i]=p[a[i]];
		p[a[i]]=i;
		r[i][min(i,k)+1]=i-1;
	}
	for(i=1;i<=n;i++){
		for(j=pre[i]+1;j<=i;j++){
			u[j]++;
		}
		dp[i][1]=u[1];
		//printf("dp[%d][%d]=%d\n",i,1,dp[i][1]);
		for(j=min(i,k);j>=2;j--){
			int pos=j-1;
			for(l=r[i-1][j];l<=r[i][j+1];l++){
				if(dp[l][j-1]+u[l+1]>dp[pos][j-1]+u[pos+1])
					pos=l;
			}
			r[i][j]=pos;
			dp[i][j]=dp[pos][j-1]+u[pos+1];
			//printf("dp[%d][%d]=%d pos=%d\n",i,j,dp[i][j],pos);
		}
	}
	printf("%d\n",dp[n][k]);
 return 0;
}

