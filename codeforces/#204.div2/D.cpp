#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a[3010],i,j;
	long long rev=0,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(a[i]>a[j]) rev++;
	printf("%I64d.000000",rev/2*4+rev%2);
 return 0;
}
