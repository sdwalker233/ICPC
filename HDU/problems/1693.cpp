#include <bits/stdc++.h>
#define MAXN 12
using namespace std;
int n,m;
int maze[MAXN][MAXN],code[MAXN];
long long dp[2][10010];

void decode(int code[],int m,int mask)
{
	int i;
	for(i=0;i<=m;i++){
		code[i]=mask&1;
		mask>>=1;
	}
}

int encode(int code[],int m)
{
	int i,mask=0;
	for(i=m;i>=0;i--){
		mask<<=1;
		mask|=code[i];
	}
	return mask;
}

void shift(int code[],int m)
{
	int i;
	for(i=m;i>0;i--) code[i]=code[i-1];
	code[0]=0;
}

void dpblock(int i,int j,int cur)
{
	int k;
	for(k=0;k<(1<<(m+1));k++){
		if(dp[cur][k]==0) continue;
		decode(code,m,k);
		code[j-1]=code[j]=0;
		if(j==m) shift(code,m);
		dp[cur^1][encode(code,m)]+=dp[cur][k];
	}
}

void dpblank(int i,int j,int cur)
{
	int k;
	for(k=0;k<(1<<(m+1));k++){
		if(dp[cur][k]==0) continue;
		decode(code,m,k);
		int left=code[j-1],up=code[j];
		if(left&&up){
			code[j-1]=code[j]=0;
			if(j==m) shift(code,m);
			dp[cur^1][encode(code,m)]+=dp[cur][k];
		}
		else if(left||up){
			if(maze[i][j+1]){
				code[j-1]=0;
				code[j]=1;
				dp[cur^1][encode(code,m)]+=dp[cur][k];
			}
			if(maze[i+1][j]){
				code[j-1]=1;
				code[j]=0;
				if(j==m) shift(code,m);
				dp[cur^1][encode(code,m)]+=dp[cur][k];
			}
		}
		else{
			if(maze[i][j+1]&&maze[i+1][j]){
				code[j]=code[j-1]=1;
				dp[cur^1][encode(code,m)]+=dp[cur][k];
			}
		}
	}
}

void fuck()
{
	int i,j,cur=0,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&maze[i][j]);
	for(i=1;i<=n;i++) maze[i][m+1]=0;
	for(i=1;i<=m;i++) maze[n+1][i]=0;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			memset(dp[cur^1],0,sizeof(dp[cur^1]));
			if(maze[i][j]) dpblank(i,j,cur);
			else dpblock(i,j,cur);
			for(k=0;k<(1<<(m+1));k++)
				printf(" %d",dp[cur^1][k]);
			printf("\n");
			cur^=1;
		}
	}
	long long ans=0;
	for(i=0;i<(1<<(m+1));i++){
		ans+=dp[cur][i];
	}
	printf("There are %lld ways to eat the trees.\n",ans);
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case %d: ",i);
		fuck();
	}
 return 0;
}

