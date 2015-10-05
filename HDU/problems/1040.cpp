#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	int m,n,i,a[1000];
	scanf("%d",&m);
	while(m--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		for(i=0;i<n-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[i]);
	}
 return 0;
}

