#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	double x1,x2,x3,y1,y2,y3,a,b,c,z3,z2,k;
	scanf("%d",&t);
	while(t--){
		scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
		a=(y2-y1)/(x2-x1)/(x2-x1);
		k=(y2-y3)/(x2-x3);
		z2=a*(x2-x1)*(x2-x1)*(x2-x1)/3+(y1-y2+k*x2)*x2-k*x2*x2/2;
		z3=a*(x3-x1)*(x3-x1)*(x3-x1)/3+(y1-y2+k*x2)*x3-k*x3*x3/2;
		printf("%.2lf\n",fabs(z2-z3));
	}
 return 0;
}

