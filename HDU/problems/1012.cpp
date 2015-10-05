#include<stdio.h>

int main()
{
	double ans[11];
	int i,a[11];
	a[0]=1;ans[0]=1;
	for(i=1;i<=9;i++)
		a[i]=a[i-1]*i;
	for(i=1;i<=9;i++)
		ans[i]=ans[i-1]+1/(double)a[i];
	printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n");
	for(i=3;i<=9;i++)
		printf("%d %.9lf\n",i,ans[i]);
 return 0;
}

