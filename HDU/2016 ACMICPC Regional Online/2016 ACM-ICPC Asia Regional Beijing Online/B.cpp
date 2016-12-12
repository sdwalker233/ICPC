#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 500010
using namespace std;
int n,m,p[MAXN],a[MAXN];
long long K;

void fuck()
{
	int i,j,k,ans=0;
	scanf("%d%d%lld",&n,&m,&K);
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			int len=j-i+1;
			for(k=i;k<=j;k++) a[k-i+1]=p[k];
			sort(a+1,a+len+1+1);
			long long v=0;
			for(k=1;k<=m;k++){
				if(k>=len-k+1) break;
				v+=(a[len-k+1]-a[k])*(a[len-k+1]-a[k]);
			}
			if(v>K) break;
		}
		++ans;
		i=j-1;
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

