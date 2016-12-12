#include <bits/stdc++.h>
#define MAXN 110
using namespace std;
int n;
int a[MAXN],p[MAXN];

long long lcm(long long x,long long y)
{
	return x/__gcd(x,y)*y;
}

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++){
		int x=i;
		for(j=1;j<=n+1;j++){
			x=a[x];
			if(x==i) break;
		}
		if(j<=n+1) p[i]=j;
		else{
			printf("-1\n");
			return 0;
		}
	}
	for(i=1;i<=n;i++){
		if(p[i]%2==0) p[i]/=2;
	}
	long long ans=1;
	for(i=1;i<=n;i++){
	//	printf("%d %d\n",i,p[i]);
		ans=lcm(ans,p[i]);
	}
	cout<<ans<<endl;
 return 0;
}

