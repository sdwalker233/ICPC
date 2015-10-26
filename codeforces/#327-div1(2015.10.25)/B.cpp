#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps=1e-8;
const double pi=acos(-1);

int main()
{
	double x1,x2,y1,y2,vm,t;
	double vx,vy,wx,wy,v,w;
	double a,b,c,cs,dis,d,ans,ans1,ans2;
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
	scanf("%lf%lf",&vm,&t);
	scanf("%lf%lf%lf%lf",&vx,&vy,&wx,&wy);
	v=hypot(vx,vy);
	w=hypot(wx,wy);
	
	dis=hypot(x1-x2,y1-y2);
	if(dis<eps){
		printf("0\n");
		return 0;
	}
	cs=((x2-x1)*vx+(y2-y1)*vy)/(dis*v);
	a=vm*vm-v*v;
	b=2*v*dis*cs;
	c=0-dis*dis;
	d=b*b-4*a*c;
	ans1=(sqrt(d)-b)/(2*a);
	ans2=(0-sqrt(d)-b)/(2*a);
	ans=min(ans1,ans2);
	if(ans<0) ans=max(ans1,ans2);
	if(v<eps) ans=dis/vm;
	if(ans<=t&&ans>=0){
		printf("%.15lf\n",ans);
		return 0;
	}

	x1+=t*vx;
	y1+=t*vy;
	dis=hypot(x1-x2,y1-y2);
	if(dis<eps){
		printf("%.15lf\n",t);
		return 0;
	}
	cs=((x2-x1)*wx+(y2-y1)*wy)/(dis*w);
	a=vm*vm-w*w;
	b=2*w*w*t+2*w*dis*cs;
	c=0-w*w*t*t-dis*dis-2*w*t*dis*cs;
	d=b*b-4*a*c;
	ans1=(sqrt(d)-b)/(2*a);
	ans2=(0-sqrt(d)-b)/(2*a);
	ans=min(ans1,ans2);
	if(ans<=t) ans=max(ans1,ans2);
	if(w<eps) ans=dis/vm;
	printf("%.15lf\n",ans);

 return 0;
}