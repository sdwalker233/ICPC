#include<stdio.h>
int main()
{
	double n,sum;
	int i;
	while(scanf("%lf",&n)!=EOF && n!=0)
	{
		sum=0;
		for(i=2;sum<n;i++)
			sum=sum+1.0/i;
		printf("%d card(s)\n",i-2);
	}
	return 0;
}
