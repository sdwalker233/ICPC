#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const double eps = 1E-6;
int sig(double d) {
	return (d>eps) - (d<-eps);
}
struct Point {
	double x, y;
	bool operator < (const Point & p) const {
		return sig(x-p.x)!=0 ? x<p.x : sig(y-p.y)<0;
	}
};
double cross(Point o, Point a, Point b) {
	return (a.x - o.x)*(b.y - o.y)-(b.x - o.x)*(a.y - o.y);
}
double dot(Point &o, Point &a, Point &b) {
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y);
}
int btw(Point &x, Point &a, Point &b) {
	return sig(dot(x, a, b));
}
/*	判断线段a,b   和   c,d是否相交
	
	类型			返回	p 
--------------------------------------
1.	不相交			0		不变
2.	规范相交		1		交点
3.	非规范相交		2		不变 
*/
int segCross(Point a, Point b, Point c, Point d, Point &p) {
	double s1, s2;
	int d1, d2, d3, d4;
	d1 = sig(s1=cross(a,b,c));
	d2 = sig(s2=cross(a,b,d));
	d3 = sig(cross(c,d,a));
	d4 = sig(cross(c,d,b));
	if((d1^d2)==-2 && (d3^d4)==-2) {
		p.x = (c.x*s2-d.x*s1)/(s2-s1);
		p.y = (c.y*s2-d.y*s1)/(s2-s1); 
		return 1;
	}
	if( d1==0 && btw(c,a,b)<=0 ||
		d2==0 && btw(d,a,b)<=0 ||
		d3==0 && btw(a,c,d)<=0 ||
		d4==0 && btw(b,c,d)<=0)
		return 2;
	return 0;
}
int main()
{
	int n,i,j,ans;
	Point l[110],r[110],q;
	while(~scanf("%d",&n)&&n){
		ans=0;
		for(i=1;i<=n;i++)
			scanf("%lf%lf%lf%lf",&l[i].x,&l[i].y,&r[i].x,&r[i].y);
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(segCross(l[i],r[i],l[j],r[j],q)) ans++;
		printf("%d\n",ans);
	}
 return 0;
}

