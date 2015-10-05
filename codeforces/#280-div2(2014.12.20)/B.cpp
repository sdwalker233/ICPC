#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	int n,l,a[1001],i,last=0;
	float max;
	scanf("%d%d",&n,&l);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	max=a[0]>l-a[n-1]?a[0]:l-a[n-1];
	for(i=0;i<n-1;i++)
		if((float)(a[i+1]-a[i])/2>max) max=(float)(a[i+1]-a[i])/2;
	printf("%.10f",max);
 return 0;
}

