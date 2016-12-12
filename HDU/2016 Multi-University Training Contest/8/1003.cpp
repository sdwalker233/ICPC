#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 20
using namespace std;
const int mod=1e9+7;
int n,m,g[MAXN][MAXN];
int con[1<<18|1],to[MAXN],nxt[1<<18|1];
int ans[1<<18|1],ret[1<<18|1],pro[1<<18|1];

void fwt(int l,int r,int a[])
{
	int i;
	if(l==r-1) return;
	int len=(r-l)>>1;
	int m=l+len;
	fwt(l,m,a);
	fwt(m,r,a);
	for(i=l;i<m;i++){
		long long x1=a[i],x2=a[i+len];
		a[i]=x1;
		a[i+len]=(x1+x2)%mod;
	}
}

void ifwt(int l,int r,int a[])
{
	int i;
	if(l==r-1) return;
	int len=(r-l)>>1;
	int m=l+len;
	for(i=l;i<m;i++){
		long long y1=a[i],y2=a[i+len];
		a[i]=y1;
		a[i+len]=(y2-y1+mod)%mod;
	}
	ifwt(l,m,a);
	ifwt(m,r,a);
}

void gao()
{
	int i,j;
	m=(1<<n);
	//memset(con,0,sizeof(con));
	memset(to,0,sizeof(to));
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			if(g[i][j]) to[i]|=(1<<j);
	}
	pro[0]=1;
	for(i=1;i<m;i++){
		con[i]=pro[i]=1;
		for(j=0;j<n;j++){
			if((i&(1<<j))==0) continue;
			int mask=(i^(1<<j));
			if(mask&to[j]) con[i]=0;
		}
		//printf("  %d %d\n",i,con[i]);
	}
}

void fuck()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%1d",&g[i][j]);
	gao();
	fwt(0,m,con);
	memset(ans,0,sizeof(ans));
	for(i=1;i<=n;i++){
		for(j=0;j<m;j++){
			pro[j]=(long long)pro[j]*con[j]%mod;
			ret[j]=pro[j];
		}
		ifwt(0,m,ret);
		for(j=0;j<m;j++)
			if(ans[j]==0&&ret[j]) ans[j]=i;
	}
	int r=0,a=1;
	for(i=1;i<=m;i++){
		//printf(" %d %d\n",i,ans[i]);
		a*=233;
		r+=ans[i]*a;
	}
	printf("%u\n",r);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

