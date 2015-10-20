#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[50010];

bool run()
{
	int i;
	long long sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		sum+=a[i];
		if(sum<(long long)i*(i-1)/2) return 0;
	}
	if(sum!=(long long)n*(n-1)/2) return 0;
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		if(run()) printf("It seems to have no problem.\n");
		else printf("The data have been tampered with!\n");
 return 0;
}