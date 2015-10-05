#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long ans[40];

int main()
{
	int i,n;
	for(i=1;i<=35;i++)
		ans[i]=ans[i-1]*3+2;
	while(~scanf("%d",&n))
		printf("%I64d\n",ans[n]);
 return 0;
}


