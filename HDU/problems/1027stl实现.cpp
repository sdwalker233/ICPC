#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1001],n,m;

 void run()
 {
 	int i;
 	for(i=1;i<=n;i++)
 		a[i]=i;
 	for(i=1;i<m;i++)
 		next_permutation(a+1,a+n+1);
 	for(i=1;i<n;i++)
 		printf("%d ",a[i]);
 	printf("%d\n",a[n]);
 }

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
		run();
 return 0;
}

