#include<stdio.h>
#include<math.h>
double s(int x1,int y1,int x2,int y2,int x3,int y3);

int main()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int x[100],y[100];
		double S=0;
		for (i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
		for (j=1;j<=n-2;j++) S+=s(x[0],y[0],x[j],y[j],x[j+1],y[j+1]);
		printf("%.1f\n",S);
	}
	return 0;
}

double s(int x1,int y1,int x2,int y2,int x3,int y3)
{
	double s1;
	s1=(x1*y2+x3*y1+x2*y3-x3*y2-x2*y1-x1*y3)/2.0;
	return s1;
}
