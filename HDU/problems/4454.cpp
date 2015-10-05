#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#define eps 1e-8
using namespace std;
int dx[]={1,-1};
double sx,sy,cx,cy,r,xl,xr,yl,yr;

double dis(double xa,double ya,double xb,double yb)
{
	return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}

double f(double x,double y)
{
	double dis1=dis(sx,sy,x,y),tmp;
	if(x>=xl&&x<=xr) return min(fabs(y-yl),fabs(y-yr))+dis1;
	if(y>=yl&&y<=yr) return min(fabs(x-xl),fabs(x-xr))+dis1;
	tmp=min(dis(x,y,xl,yl),dis(x,y,xl,yr));
	tmp=min(dis(x,y,xr,yl),tmp);
	tmp=min(dis(x,y,xr,yr),tmp);
	return tmp+dis1;
}

double caly(double x)
{
	double tmp=r*r-(x-cx)*(x-cx),sol1,sol2;
	if(tmp<0) return 1000000010;
	tmp=sqrt(tmp);
	sol1=cy+tmp;sol2=cy-tmp;
	if(f(x,sol1)<f(x,sol2)) return sol1;
	else return sol2;
}

double Simulated_Annealing()
{
	double x=cx,y=cy+r,nx,ny,step=100000,rate=0.9;
	while(step>eps){
		for(int i=0;i<=1;i++){
			nx=x+step*dx[i];
			ny=caly(nx);
			if(ny>1000000000) continue;
			if(f(nx,ny)<f(x,y)){
				x=nx;y=ny;
			}
		}
		step*=rate;
	}
	//printf("%lf %lf\n",x,y);
	return f(x,y);
}

int main()
{
	while(~scanf("%lf%lf",&sx,&sy)){
		if(fabs(sx)<eps&&fabs(sy)<eps) break;
		scanf("%lf%lf%lf%lf%lf%lf%lf",&cx,&cy,&r,&xl,&yl,&xr,&yr);
		if(xl>xr) swap(xl,xr);
		if(yl>yr) swap(yl,yr);
		printf("%.2lf\n",Simulated_Annealing());
	}
 return 0;
}

