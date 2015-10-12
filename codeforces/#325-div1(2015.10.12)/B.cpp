#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dx[3]={-1,1,0};
int n,k,a[4][110];
char g[4][110];
bool dp[4][110];

void fuck()
{
	int i,j,k;
	memset(dp,0,sizeof(dp));
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&k);
	for(i=1;i<=3;i++){
		scanf("%s",&g[i][1]);
		for(j=1;j<=n;j++)
			if(g[i][j]!='.'&&g[i][j]!='s') a[i][j]=1;
		if(g[i][1]=='s') dp[i][1]=1;
	}
	for(j=4;j<=(n+2)/3*3+1;j+=3){
		for(i=1;i<=3;i++){
			if(a[i][j]||a[i][j-1]||a[i][j-2]) continue;
			for(k=0;k<3;k++){
				int xx=i+dx[k];
				if(xx<1||xx>3) continue;
				if(dp[xx][j-3]&&a[xx][j-2]==0) dp[i][j]=1;
			}
		}
	}
	/*for(i=1;i<=3;i++){
		for(j=1;j<=(n+2)/3*3+1;j++)
			printf(" %d",a[i][j]);
		printf("\n");
	}*/
	if(dp[1][(n+2)/3*3+1]||dp[2][(n+2)/3*3+1]||dp[3][(n+2)/3*3+1]) printf("YES\n");
	else printf("NO\n");
	
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}


