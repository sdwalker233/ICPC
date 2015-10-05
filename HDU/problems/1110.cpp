#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979323846
#define eps 1e-8

double x,y,a,b;

bool fuck()
{
	double t;
	double ang,l,H;
	scanf("%lf%lf%lf%lf",&x,&y,&a,&b);
	if(x<y){t=x;x=y;y=t;}
	if(a<b){t=a;a=b;b=t;}
	if(x*y<=a*b) return 0;
	if(x>a&&y>b) return 1;
	if(b>=y) return 0;
	l=sqrt(a*a+b*b);
	ang=atan(b/a)+acos(y/l);
	H=a*sin(ang)+b*cos(ang);
	if(H<x) return 1;
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		if(fuck()) printf("Escape is possible.\n");
		else printf("Box cannot be dropped.\n");
 return 0;
}

