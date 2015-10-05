#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long a[100010],b[100010];

void fuck()
{
	int n,m,i,j;
	long long sum=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)	scanf("%lld",&a[i]);
	for(i=1;i<=m;i++)	scanf("%lld",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for(i=1;i<=min(m,n);i++){
		if(a[n-i+1]<b[i]) break;
		sum+=a[n-i+1]-b[i];
	}
	printf("%lld\n",sum);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		fuck();
	}
 return 0;
}

