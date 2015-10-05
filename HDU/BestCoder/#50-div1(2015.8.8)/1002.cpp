#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long ans[100]={0};

void init()
{
	int i,j;
	long long a[100]={0};
	a[0]=1;a[1]=1;a[2]=1;a[3]=1;
	for(i=4;i<=60;i++){
		for(j=0;j<=i-3;j++){
			a[i]+=a[j];
		}
	}
	for(i=1;i<=60;i++){
		for(j=1;j<=i;j++)
			ans[i]+=a[j];
	}
}

int main()
{
	int n;
	init();
	while(~scanf("%d",&n)){
		printf("%lld\n",ans[n]);
	}
 return 0;
}

