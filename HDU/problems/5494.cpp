#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,a[1010],b[1010];

void run()
{
	int i,suma=0,sumb=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(i=1;i<=m;i++){
		suma+=a[i];
		sumb+=b[n-i+1];
	}
	if(suma>sumb) printf("YES\n");
	else printf("NO\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		run();
 return 0;
}