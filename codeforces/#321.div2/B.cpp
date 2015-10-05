#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
	int m,s;
}a[100010];
long long sum[100010]={0};
int b[100010];
int p;

bool cmp(const node& x,const node& y)
{
	return x.m<y.m;
}

int main()
{
	int n,d,i,j;
	long long mx=0;
	scanf("%d%d",&n,&d);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i].m,&a[i].s);
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i].s;
		b[i]=a[i].m;
	}
	for(i=1;i<=n;i++){
		p=lower_bound(b+1,b+n+1,b[i]+d)-b-1;
		//printf("%d\n",p); 
		mx=max(mx,sum[p]-sum[i-1]);
	}
	cout<<mx<<endl;
 return 0;
}
/*
7 100
0 7
11 32
46 8
87 54
99 10
100 100
101 100
*/
