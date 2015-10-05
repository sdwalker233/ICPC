#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ttt 0.8660254
#define PI 3.141592653589793
using namespace std;

int main()
{
	int x1,x2,x3,x4,x5,x6;
	double sum=0,p,alph;
	scanf("%d%d%d%d%d%d",&x1,&x2,&x3,&x4,&x5,&x6);
	p=sqrt((double)x1*x1+x2*x2+x1*x2);
	alph=asin(ttt*x1/p);
	alph=(double)2/3*PI-alph;
	sum+=p*x3*sin(alph)/2;
	sum+=(double)x1*x2*sqrt(3)/4;
	
	p=sqrt(x4*x4+x5*x5+x4*x5);
	alph=asin(sqrt(3)/2*x4/p);
	alph=(double)2/3*PI-alph;
	sum+=p*x6*sin(alph)/2;
	sum+=(double)x4*x5*sqrt(3)/4;
	//printf("%lf\n",sum);
	printf("%.0lf",sum/(sqrt(3)/4));
 return 0;
}

