#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[200011],b[200011],n;

int main()
{
	int n,i;
	bool ok=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]+=i;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		b[i]=a[i]-i;
		if((i>=2&&b[i-1]>b[i])||b[i]<0) ok=0;
	}
	if(ok)
		for(i=1;i<=n;i++)
			printf("%d ",b[i]);
	else printf(":(");
 return 0;
}

