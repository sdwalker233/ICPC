#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,f[100],b[100];

void init()
{
	int i;
	b[0]=1;
	for(i=1;i<=59;i++)
		b[i]=b[i-1]*2;
	f[1]=1;
	for(i=2;i<=59;i++){
		f[i]=2*f[i-1]+b[i-2];
		//printf(" %d %I64d\n",i,f[i]);
	}
}

long long cal(long long x)
{
	if(x<=0) return 0;
	int i,j;
	long long sum=0,sum2=0;
	for(i=0;i<=59;i++){
		if(sum+b[i]>x) break;
		else sum+=b[i];
	}
	for(j=1;j<=i;j++)
		sum2+=f[j];
	//printf(" %d\n",i);
	return sum2+x-sum+cal(x-sum-1);
}

int main()
{
	int t;
	init();
	scanf("%d",&t);
	while(t-->0){
		scanf("%I64d",&n);
		printf("%I64d\n",cal(n));
	}
 return 0;
}