#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;
struct node{
	long long v;
	int d,index;
}g[MAXN];
int n,m,k,s;
long long a[MAXN],b[MAXN];
long long mn[3][MAXN];
int t[MAXN];
int d[3][MAXN];
int c[MAXN];

bool cmp(const node& x,const node& y)
{
	return x.v<y.v;
}

bool check(int x)
{
	long long sum=0;
	int i;
	for(i=1;i<=m;i++){
		g[i].v=mn[t[i]][x]*c[i];
		g[i].d=d[t[i]][x];
		g[i].index=i;
	}
	nth_element(g+1,g+k+1,g+m+1,cmp);
	for(i=1;i<=k;i++)
		sum+=g[i].v;
	if(sum<=s) return 1;
	else return 0;
}

int main()
{
	int i;
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for(i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%I64d",&b[i]);
	for(i=1;i<=m;i++)
		scanf("%d%d",&t[i],&c[i]);
	mn[1][0]=mn[2][0]=0x7fffffff;
	for(i=1;i<=n;i++){
		mn[1][i]=min(mn[1][i-1],a[i]);
		mn[2][i]=min(mn[2][i-1],b[i]);
		if(mn[1][i-1]<a[i]) d[1][i]=d[1][i-1];
		else d[1][i]=i;
		if(mn[2][i-1]<b[i]) d[2][i]=d[2][i-1];
		else d[2][i]=i;
	}
	int l=1,r=n,m,ans=n;
	while(l<=r){
		m=(l+r)>>1;
		if(check(m)){
			ans=m;
			r=m-1;
		}
		else l=m+1;
	}
	if(!check(ans)){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",ans);
	for(i=1;i<=k;i++){
		printf("%d %d\n",g[i].index,g[i].d);
	}
 return 0;
}


