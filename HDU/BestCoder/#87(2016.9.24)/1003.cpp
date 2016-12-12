#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;
int n,m,a[MAXN],b[MAXN],mx;
int aa[MAXN],bb[MAXN];
int pa[MAXN],pb[MAXN];
int lena[MAXN],lenb[MAXN];

void fuck()
{
	int i,j;
	scanf("%d%d",&n,&m);
	memset(pa,0,sizeof(pa));
	memset(pb,0,sizeof(pb));
	memset(aa,0,sizeof(aa));
	memset(bb,0,sizeof(bb));
	memset(lena,0,sizeof(lena));
	memset(lenb,0,sizeof(lenb));
	a[0]=b[0]=aa[0]=bb[0]=mx=0;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
		pa[a[i]]=i;
		if(aa[pa[a[i]-1]])	aa[i]=aa[pa[a[i]-1]];
		else aa[i]=i;
	}
	for(i=1;i<=m;i++){
		scanf("%d",&b[i]);
		mx=max(mx,b[i]);
		pb[b[i]]=i;
		if(bb[pb[b[i]-1]])	bb[i]=bb[pb[b[i]-1]];
		else bb[i]=i;
	}
	int ans=0;
	/*for(i=1;i<=n;i++)
		printf(" %d %d\n",aa[i],pa[i]);
	for(i=1;i<=m;i++)
		printf(" %d %d\n",bb[i],pb[i]);
	*/
	for(i=1;i<=n;i++)
		lena[a[i]]=a[i]-a[aa[i]]+1;
	for(i=1;i<=m;i++)
		lenb[b[i]]=b[i]-b[bb[i]]+1;
	for(i=1;i<=mx;i++){
		ans=max(ans,min(lena[i],lenb[i]));
	}
	printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

