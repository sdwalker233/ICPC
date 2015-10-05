#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-8;
struct Point{
	double x,y;
	bool flag;
}p[20010],g[40010],h[40010];
int n,cntg,cnth;
double a,b,c,l,r;

bool cmp1(const Point& x,const Point& y)
{
	return x.x<y.x;
}

int cmp(double x,double y)
{
	if(fabs(x-y)<eps) return 0;
	if(x>y) return 1;
	return -1;
}

double f(double x)
{
	return a*x*x+b*x+c;
}

double ff(double x)
{
	return (x*sqrt(x*x+1)/2+log(x+sqrt(x*x+1))/2)/(2*a);
}

void add(int i,double x,double y)
{
	
	int x1,x2,y1,y2,xx,yy;
	if(cmp(p[i].x,x)==0&&cmp(p[i].y,y)==0){
		//printf("  %.2lf %.2lf %d\n",x,y,i);
		xx=p[i+1].x-x;yy=p[i+1].y-y;
		x1=x+xx/sqrt(xx*xx+yy*yy)*2;y1=y+yy/sqrt(xx*xx+yy*yy)*2;
		xx=p[i-1].x-x;yy=p[i-1].y-y;
		x2=x+xx/sqrt(xx*xx+yy*yy)*2;y2=y+yy/sqrt(xx*xx+yy*yy)*2;
		//printf(" %d %d\n",cmp(f(x1),y1),cmp(f(x2),y2));
		if(cmp(f(x1),y1)!=cmp(f(x2),y2)) return;
	}
	++cntg;
	g[cntg].x=x;
	g[cntg].y=y;
	//printf("  %.2lf %.2lf\n",x,y);
}

void fuck()
{
	int i;
	bool left=1;
	double k,d,x1,x2,y1,y2,del,xx,yy,ans=0;
	cntg=0,cnth=0;
	for(i=1;i<=n;i++){
		scanf("%lf%lf",&p[i].x,&p[i].y);
	}
	p[0].x=p[n].x;p[0].y=p[n].y;
	p[n+1].x=p[1].x;p[n+1].y=p[1].y;
	for(i=1;i<=n;i++){
		if(p[i].x<=p[i+1].x){
			x1=p[i].x;y1=p[i].y;
			x2=p[i+1].x;y2=p[i+1].y;
		}
		else{
			x1=p[i+1].x;y1=p[i+1].y;
			x2=p[i].x;y2=p[i].y;
		}
		if(cmp(x1,x2)==0){
			if(cmp(y1,y2)==1) swap(y1,y2);
			yy=f(x1);
			if(cmp(y1,yy)!=1&&cmp(y2,yy)!=-1){
				add(i,x1,yy);
			}
			continue;
		}
		k=(y1-y2)/(x1-x2);
		d=y1-k*x1;
		del=(b-k)*(b-k)-4*a*(c-d);
		if(del<eps) continue;
		del=sqrt(del);
		xx=(k-b+del)/(2*a);
		if(cmp(xx,x1)!=-1&&cmp(xx,x2)!=1){
			add(i,xx,k*xx+d);
		}
		xx=(k-b-del)/(2*a);
		if(cmp(xx,x1)!=-1&&cmp(xx,x2)!=1){
			add(i,xx,k*xx+d);
		}
	}
	sort(g+1,g+cntg+1,cmp1);

	for(i=1;i<=cntg;i++){
		g[i].flag=left;
		left^=1;
		if(cmp(l,g[i].x)!=1&&cmp(g[i].x,r)!=1){
			h[++cnth]=g[i];
		}
	}
	h[0].x=l;h[0].y=f(l);h[0].flag=1;
	++cnth;
	h[cnth].x=r;h[cnth].y=f(r);h[cnth].flag=0;
	/*
	for(i=0;i<=cnth;i++){
		printf(" %.2lf %.2lf %d\n",h[i].x,h[i].y,h[i].flag);
	}
	*/
	for(i=0;i<cnth;i++){
		if(h[i].flag==1&&h[i+1].flag==0){
			if(cmp(h[i].x,h[i+1].x)==0) continue;
			ans+=ff(2*a*h[i+1].x+b)-ff(2*a*h[i].x+b);
		}
	}
	printf("%.2lf\n",ans);
}

int main()
{
	while(~scanf("%d%lf%lf%lf%lf%lf",&n,&a,&b,&c,&l,&r)){
		fuck();
	}
 return 0;
}
/*
5 1 0 0 -100 100
-1 1
-1 0
0 0
1 0
1 1

4 1 0 0 -10 10 
4 4 
1 1 
1 0 
0 1
*/

