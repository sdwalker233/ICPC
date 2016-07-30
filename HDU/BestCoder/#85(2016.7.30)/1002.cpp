#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
using namespace std;
long long n,k;
long long a[100010];

void fuck()
{
	int i;
	scanf("%lld%lld",&n,&k);
	for(i=1;i<n;i++) scanf("%lld",&a[i]);
	if(k>=n){printf("%d\n",n);return;}
	int p=n-k;
	sort(a+1,a+n);
	//nth_element(a+1,a+p+1,a+n);
	printf("%lld\n",accumulate(a+1,a+p+1,n));
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

