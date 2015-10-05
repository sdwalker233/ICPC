#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);

int sgn(double x)
{
	if(fabs(x)<eps) return 0;
	if(x<0) return -1;
	else return 1;
}

struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y){
		x=_x;
		y=_y;
	}
	Point operator -(const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	double operator ^(const Point &b)const{
		return x*b.y-y*b.x;
	}
	double operator *(const Point &b)const{
		return x*b.x+y*b.y;
	}
	Point operator +(const Point &b)const{
		return Point(x+b.x,y+b.y);
	}
	Point operator *(const double &k)const{
		return Point(x*k,y*k);
	}
	Point operator /(const double &k)const{
		return Point(x/k,y/k);
	}
	Point rotate(Point p,double angle){
		Point v=(*this)-p;
		double c=cos(angle),s=sin(angle);
		return Point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
	}
	double len2(){
		return x*x+y*y;
	}
};

struct Line{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e){
		s=_s;
		e=_e;
	}
	Point crosspoint(Line v){
		double a1=(v.e-v.s)^(s-v.s);
		double a2=(v.e-v.s)^(e-v.s);
		return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
	}
	Point lineprog(Point p){
		return s+( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) );
	}
};

void fuck()
{
	int n,i;
	double x,y,p,nx,ny,np;
	Point a,b,c,d,e,f,g;
	Line l1,l2,l3,l4;
	scanf("%d",&n);
	scanf("%lf%lf%lf",&nx,&ny,&np);
	for(i=2;i<=n;i++){
		scanf("%lf%lf%lf",&x,&y,&p);
		a=Point(nx,ny);b=Point(x,y);
		d=a.rotate(b,p);c=b.rotate(a,-np);
		l1=Line(c,b);l2=Line(a,d);
		e=l1.lineprog(a);f=l2.lineprog(b);
		l3=Line(a,e);l4=Line(b,f);
		g=l3.crosspoint(l4);
		nx=g.x;ny=g.y;
		np=np+p;
		if(np>2*pi) np-=2*pi;
	}
	printf("%lf %lf %lf\n",nx,ny,np);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}


