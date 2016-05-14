#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[110];

void fuck()
{
	int i,j;
	int ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans=max(ans,a[i]);
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

