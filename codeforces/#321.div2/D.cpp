#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k,a[20],g[20][20];
long long dp[300000][20],ans=0;

int main()
{
	int i,j,k,x,y,c,p,t,tt,num;
	scanf("%d%d%d",&n,&m,&k);
	p=(1<<n)-1;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=k;i++){
		scanf("%d%d%d",&x,&y,&c);
		g[x][y]=c;
	}
	for(i=1;i<=n;i++){
		dp[1<<(i-1)][i]=a[i];
	}
	for(i=1;i<=p;i++){
		num=0;
		for(j=1;j<=n;j++){
			t=(1<<(j-1));
			if((i|t)!=i) continue;
			num++;
			for(k=1;k<=n;k++){
				tt=(1<<(k-1));
				if((i|tt)==i) continue;
				dp[i|tt][k]=max(dp[i|tt][k],dp[i][j]+a[k]+g[j][k]);
			}
			//printf(" %d %d %d\n",i,j,dp[i][j]);
		}
		if(num==m){
			for(j=1;j<=n;j++){
				t=(1<<(j-1));
				if((i|t)!=i) continue;
				ans=max(ans,dp[i][j]);
			}
		}
		
	}
	cout<<ans<<endl;
 return 0;
}


