#include<iostream>
#include<cstdio>
#include<algorithm>
#define eps 1e-8
using namespace std;
struct point{
	double x, y;
	point(){}
	point( double x, double y) : x(x), y(y) {}
	point operator - ( const point b ) const {
		return point( x - b.x, y - b.y);
	}
	point operator + ( const point b ) const {
		return point( x + b.x, y + b.y);
	}
}p[51];
int dx[]={-1,-1,0,1,1,1,0,-1},dy[]={0,1,1,1,0,-1,-1,-1};
double r;
int n;

int dcmp(double x){
	return (x>eps)-(x<-eps);
}
double cross( point a, point b ) {
	return a.x * b.y - a.y * b.x;
}

double dot( point a, point b ) {
	return a.x * b.x + a.y * b.y;
}
//double 要 dcmp
bool ponseg( point p, point a, point b ) {
	return cross( a - p, b - p ) == 0 && dot( a - p, b - p ) <= 0;
}
// 0:外, 1:内, 2:边
int pointInPolygon( point cp, point* p, int n ) {
	int w = 0;
	p[n] = p[0];
	for( int i = 0; i < n; ++i ) {
		if( ponseg(cp, p[i], p[i+1]) ) return 2;
		int k = dcmp(cross(p[i+1] - p[i], cp - p[i]));
		int d1 = dcmp(p[i].y - cp.y);
		int d2 = dcmp(p[i+1].y - cp.y);
		if( k > 0 && d1 <= 0 && d2 > 0 ) w++;
		if( k < 0 && d2 <= 0 && d1 > 0 ) w--;
	}
	return w != 0;
}

int cal(double x,double y)
{
	int i,cnt=0;
	for(i=0;i<n;i++){
		if((p[i].x-x)*(p[i].x-x)+(p[i].y-y)*(p[i].y-y)<r*r) cnt++;
	}
	return cnt;
}

bool Simulated_Annealing()
{
	double x=0,y=0,nx,ny,step=1000,rate=0.5;
	int i,num;
	while(step>eps){
		for(i=0;i<8;i++){
			nx=x+step*dx[i];
			ny=y+step*dy[i];
			if(pointInPolygon(point(nx,ny),p,n)!=1) continue;
			printf("%lf %lf\n",nx,ny);
			num=cal(nx,ny);
			if(num==0){
				printf("%lf %lf\n",nx,ny);
				return 1;
			}
			if(num<cal(x,y)){
				x=nx;y=ny;
			}
		}
		step*=rate;
	}
	return 0;
}

int main()
{
	int n,i;
	while(~scanf("%d",&n)&&n){
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		scanf("%lf",&r);
		if(Simulated_Annealing()) printf("Yes\n");
		else printf("No\n");
	}
 return 0;
}
