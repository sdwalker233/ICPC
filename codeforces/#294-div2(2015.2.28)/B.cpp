#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	int n,i,m,a[100001],b[100001],c[100001];
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<n;i++) scanf("%d",&b[i]);
	for(i=1;i<n-1;i++) scanf("%d",&c[i]);
	b[n]=c[n-1]=-1;
	sort(a+1,a+n+1);
	sort(b+1,b+n);
	sort(c+1,c+n-1);
	for(i=1;i<=n;i++)
		if(a[i]!=b[i]){
			printf("%d\n",a[i]);
			break;
		}
	for(i=1;i<n;i++)
		if(b[i]!=c[i]){
			printf("%d\n",b[i]);
			break;
		}
 return 0;
}

