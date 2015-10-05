#include<stdio.h>

int main()
{
	int count=0;
	double a,b,c;
	while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF&&a&&b&&c)
		printf("Trip #%d: %.2lf %.2lf\n",++count,a*b*3.1415927/12/5280,a*b*3.1415927/12/5280/c*3600);
 return 0;
}

