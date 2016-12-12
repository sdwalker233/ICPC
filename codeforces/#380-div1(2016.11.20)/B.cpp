#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
int n,a,b,k;
int p[MAXN],d[MAXN],c[MAXN],sum[MAXN];
vector<int> ans;

int main()
{
	int i,j,x,cnt=0;
	scanf("%d%d%d%d",&n,&a,&b,&k);
	for(i=1;i<=n;i++){
		scanf("%1d",&x);
		if(x) p[++cnt]=i;
	}
	x=0;
	p[0]=0;p[k+1]=n+1;
	for(i=0;i<=k;i++){
		d[i]=p[i+1]-p[i]-1;
		c[i]=d[i]/b;
		x+=c[i];
		//printf("  %d %d\n",i,d[i]);
	}
	a=x-a;
	//for(i=k;i>=0;i--) sum[i]=sum[i+1]+c[i];
	for(i=0;i<=k;i++){
		for(j=1;j<=c[i];j++){
			ans.push_back(p[i]+j*b);
			//printf(" %d %d %d\n",i,p[i],j);
			a--;
			if(a<0) break;
		}
		if(a<0) break;
	}
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();i++) printf("%d ",ans[i]);
 return 0;
}

