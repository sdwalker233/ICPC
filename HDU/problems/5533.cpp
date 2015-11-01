#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,x[110],y[110];

bool fuck()
{
	int i,j,cnt=0;
	int a[10];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	if(n!=4) return 0;
	for(i=1;i<=4;i++){
		for(j=i+1;j<=4;j++){
			a[++cnt]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		}
	}
	sort(a+1,a+cnt+1);
	if(a[1]==a[2]&&a[1]==a[3]&&a[1]==a[4]&&2*a[1]==a[5]&&a[5]==a[6]) return 1;
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		if(fuck()) printf("YES\n");
		else printf("NO\n");
 return 0;
}