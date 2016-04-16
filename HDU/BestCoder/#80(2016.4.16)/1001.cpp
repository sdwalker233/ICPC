#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[100010];

bool fuck()
{
	int i;
	bool f0=0,f1=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1) f1=1;
		if(a[i]==0) f0=1;
	}
	if(f0&&f1) return 1;
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

