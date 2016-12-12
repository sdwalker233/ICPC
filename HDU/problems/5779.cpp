#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 65
using namespace std;
const int mod=1e9+7;
long long A[MAXN][MAXN],B[MAXN*MAXN],C[MAXN][MAXN];
int n,k;
long long dp[MAXN][MAXN][MAXN];

void init()
{
	int i,j;
	for(i=1;i<=60;i++){
		C[i][0]=C[i][i]=1;
		for(j=1;j<i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	B[0]=1;
	for(i=1;i<=3600;i++) B[i]=(B[i-1]*2)%mod;
	for(i=1;i<=60;i++){
		A[i][0]=1;
		for(j=1;j<=60;j++)
			A[i][j]=(A[i][j-1]*(B[i]-1))%mod;
	}
}

void fuck()
{
	int i,j,p,q,d;
	scanf("%d%d",&n,&k);
	memset(dp,0,sizeof(dp));
	dp[1][0][1]=1;
	for(i=2;i<=n;i++){
		for(d=1;d<i;d++){
			for(j=1;j<=i-d;j++){
				for(p=1;p<=i-d-j+1;p++){
					dp[i][d][j]+=dp[i-j][d-1][p]*B[j*(j-1)/2]%mod*A[p][j]%mod*C[i-1][j]%mod;
					dp[i][d][j]%=mod;
				}
			}
		}
	}
	//while(~scanf("%d%d%d",&i,&d,&j)) printf(" %d\n",dp[i][d][j]);
	long long ans=0;
	for(i=1;i<=n;i++){
		for(d=0;d<k;d++){
			for(j=1;j<=i-d;j++){
				//printf(" %d %d %d %d\n",i,d,j,dp[i][d][j]);
				ans+=dp[i][d][j]*C[n-1][i-1]%mod*B[(n-i)*(n-i-1)/2]%mod;
				ans%=mod;
			}
		}
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

