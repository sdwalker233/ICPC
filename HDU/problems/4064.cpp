#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int th[]={1,3,9,27,81,243,729,2187,6561,19683,59046,177147,531441,1594323};
const int mod=1e9+7;
int n,m;
char s[13][13][10];
bool all[13][13],half[13][13];
int a[13][13][10];
int dp[540000],dp0[540000];

int get_col(int mask,int pos)
{
	/*mask/=th[pos-1];
	return mask%3;*/
	return mask/th[pos-1]%3;
}

int set_col(int mask,int pos,int col)
{
	/*int tmp=mask%th[pos-1];
	mask=mask/th[pos]*3+col;
	return mask*th[pos-1]+tmp;*/
	return mask+(col-mask/th[pos-1]%3)*th[pos-1];
}

void DFS(int x,int y,int col,int mask1,int mask2,int mul)
{
	int i,dir,freedom;
	//printf(" %d %d %d %d\n",x,y,col,mul);
	if(y>m){
		dp0[mask2]+=(long long)mul*dp[mask1]%mod;
		if(dp0[mask2]>=mod) dp0[mask2]-=mod;
		return;
	}
	if(all[x][y]) freedom=1;
	else if(half[x][y]) freedom=2;
	else freedom=4;
	for(dir=0;dir<freedom;dir++){
		if(y>1&&a[x][y][dir+3]!=col) continue;
		DFS(x,y+1,a[x][y][dir+1],mask1+a[x][y][dir]*th[y-1],mask2+a[x][y][dir+2]*th[y-1],mul*4/freedom);
	}
}

void fuck()
{
	int i,j,k,mask,maxmask,dir,ml,mu,freedom,f=0;
	long long mul;
	memset(dp,0,sizeof(dp));
	memset(all,0,sizeof(all));
	memset(half,0,sizeof(half));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j){
			scanf("%s",s[i][j]);
			for(k=0;k<4;++k){
				if(s[i][j][k]=='C') a[i][j][k]=0;
				if(s[i][j][k]=='R') a[i][j][k]=1;
				if(s[i][j][k]=='F') a[i][j][k]=2;
				a[i][j][k+4]=a[i][j][k];
			}
			if(a[i][j][0]==a[i][j][1]&&a[i][j][0]==a[i][j][2]&&a[i][j][0]==a[i][j][3])
				all[i][j]=1;
			else if(a[i][j][0]==a[i][j][2]&&a[i][j][1]==a[i][j][3])
				half[i][j]=1;
		}
	for(mask=0;mask<th[m];++mask) dp[mask]=1;
	for(i=1;i<=n;i++){
		memset(dp0,0,sizeof(dp0));
		DFS(i,1,0,0,0,1);
		memcpy(dp,dp0,sizeof(dp));
	}
	int ans=0;
	for(mask=0;mask<th[m];++mask){
		ans+=dp[mask];
		if(ans>=mod) ans-=mod;
		//printf(" dp[%d]=%d\n",mask,dp[mask]);
	}
	printf("%d\n",ans);
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
