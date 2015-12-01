#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
long long a[100010],b[100010];

void fuck()
{
	int i;
	long long sum=0;
	for(i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		sum+=a[i];
		b[i]=(1890*a[i]+143)%10007-a[i];
		//printf(" %I64d\n",b[i]);
	}
	long long mx=0,s=0;
	for(i=1;i<=n;i++){
		if(s+b[i]>=0){
			s+=b[i];
			mx=max(mx,s);
		}
		else s=0;
	}
	printf("%I64d\n",sum+mx);
}

int main()
{
	while(~scanf("%d",&n))
		fuck();
 return 0;
}