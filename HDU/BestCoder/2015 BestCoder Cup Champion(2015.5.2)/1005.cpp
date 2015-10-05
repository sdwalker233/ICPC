#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,dp[210][210],f[210],a[210];

void fuck()
{
	int i,j,k,cnt=0;
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) scanf("%d",&a[i]);
	dp[1][0]=1;
	for(i=1;i<n;i++){
		for(j=0;j<n;j++){
			if(dp[i][j]){
				for(k=1;k<=m;k++)
					dp[i+1][(j+a[k])%(i+1)]=1;
			}
		}
	}
	for(i=0;i<n;i++)
	  	if(dp[n][i]) f[++cnt]=i+1; 
	printf("%d\n",cnt);
	for(i=1;i<cnt;i++) printf("%d ",f[i]);
	printf("%d\n",f[i]);
}

int main()
{
  	int t;
  	scanf("%d",&t);
  	while(t--){
		fuck();
  	}
  return 0;
}
