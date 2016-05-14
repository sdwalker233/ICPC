#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 20010
using namespace std;
int n,k,t[MAXN],p[MAXN];
int d[MAXN],a[MAXN],b[MAXN],r[MAXN];
int pos[MAXN],le[MAXN],ri[MAXN],ll[MAXN],rr[MAXN];
long long dp[MAXN][110];

struct seatree{
	int l,r;
	long long mn;
}node[110][4*MAXN];

void build(int left,int right,int n,int x)
{
	node[x][n].l=left;
	node[x][n].r=right;
	if (left==right){
		if(left==0) node[x][n].mn=0;
		else node[x][n].mn=0x7fffffff;
		return;
	}
	else{
		int mid=(left+right)>>1;
		build(left,mid,2*n,x);
		build(mid+1,right,2*n+1,x);
		node[x][n].mn=min(node[x][n<<1].mn,node[x][n<<1|1].mn);
	}
}

void insert(int po,int val,int n,int x)
{
	if (node[x][n].l==po&&node[x][n].r==po){
		node[x][n].mn=val;
		return;
	}
	else{
		int mid=(node[x][n].l+node[x][n].r)>>1; 
		if (po<=mid) insert(po,val,2*n,x);
		else	insert(po,val,2*n+1,x);
		node[x][n].mn=min(node[x][2*n].mn,node[x][2*n+1].mn);
	}
} 

long long query(int left,int right,int n,int x)
{
	if (left==node[x][n].l&&right==node[x][n].r){
		return node[x][n].mn;
	}
	int mid=(node[x][n].l+node[x][n].r)>>1; 
	if (right<=mid)	return query(left,right,2*n,x);
	if (left>mid) return query(left,right,2*n+1,x);
	return min(query(left,mid,2*n,x),query(mid+1,right,2*n+1,x));
}

void fuck()
{
	int i,j;
	memset(t,0,sizeof(t));
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&k);
	for(i=2;i<=n;i++){
		scanf("%d",&d[i]);
		pos[i]=pos[i-1]+d[i];
	}
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&r[i],&b[i]);
		le[i]=pos[i]-r[i];
		ri[i]=pos[i]+r[i];
	}
	for(i=1;i<=n;i++){
		ll[i]=lower_bound(pos+1,pos+n+1,le[i])-pos;
		rr[i]=upper_bound(pos+1,pos+n+1,ri[i])-pos-1;
	}
	for(i=n;i>=1;i--){
		t[rr[i]]=i;
	}
	int tmp=t[n];
	for(i=n;i>=1;i--){
		if(t[i]) tmp=t[i];
		p[i]=tmp;
	}
//	for(i=1;i<=n;i++){
//		printf(" %d %d %d %d\n",ll[i],rr[i],t[i],p[i]);
//	}
	for(i=0;i<=k;i++)
		build(0,n,1,i);
	for(i=1;i<=n;i++){
		tmp=min(k,i);
		for(j=0;j<=tmp;j++){
			dp[i][j]=0x7fffffff;
			if(j)
				dp[i][j]=min(dp[i-1][j-1]+a[i],dp[i][j]);
			if(i-1>=j)
				dp[i][j]=min(dp[i-1][j]+b[i],dp[i][j]);
			if(j&&ll[p[i]]>=j)
				dp[i][j]=min(query(ll[p[i]]-1,p[i]-1,1,j-1)+a[p[i]],dp[i][j]);
			if(j&&ll[i]>=j)
				dp[i][j]=min(query(ll[i]-1,i-1,1,j-1)+a[i],dp[i][j]);
			insert(i,dp[i][j],1,j);
			//printf(" dp[%d][%d]=%lld\n",i,j,dp[i][j]);
		}
	}
	long long ans=0x7fffffff;
	for(i=0;i<=k;i++)
		ans=min(ans,dp[n][i]);
	printf("%lld\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

