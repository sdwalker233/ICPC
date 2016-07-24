#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
const double eps=1e-8;
struct Point{
    double x,y,z;
    Point(double _x=0,double _y=0,double _z=0){
        x=_x;y=_y;z=_z;
    }
    Point operator-(const Point &b)const{
        return Point(x-b.x,y-b.y,z-b.z);
    }
    Point operator^(const Point &b)const{
        return Point(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);
    }
}a[5];
const int dx[]={1,0,-1,0,0,0,1,1,1,1,-1,-1,-1,-1},dy[]={0,1,0,-1,0,0,1,1,-1,-1,1,1,-1,-1},dz[]={0,0,0,0,1,-1,1,-1,1,-1,1,-1,1,-1};
double A[10],B[10],C[10],D[10],E[10],dd[10];
double X,Y,Z;

double cal(double xx,double yy,double zz)
{
    int i;
    double res=0;
    for(i=1;i<=4;i++){
        dd[i]=fabs(xx*A[i]+yy*B[i]+zz*C[i]+D[i])/E[i];
        res=max(res,dd[i]);
    }
    return res;
}

double SA()
{
    int i;
    double x=X,y=Y,z=Z;
    double r=0.94,step=2e7;
    for(int t=1;t<=2000;t++){
        double d=cal(x,y,z);
        for(i=0;i<14;i++){
            double nx=x+dx[i]*step;
            double ny=y+dy[i]*step;
            double nz=z+dz[i]*step;
            double dis=cal(nx,ny,nz);
            if(dis<d){
                x=nx;y=ny;z=nz;d=dis;
            }
        }
        step*=r;
    }
    X=x;Y=y;Z=z;
    return cal(x,y,z);
    //printf("%.4f %.4f %.4f %.4f\n",dd[1],dd[2],dd[3],dd[4]);
}

void fuck()
{
    int i,j,k,c=0;
    double ans=1e20;
    for(i=2;i<=4;i++)
        scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
    for(i=1;i<=4;i++)
        for(j=i+1;j<=4;j++)
            for(k=j+1;k<=4;k++){
                Point o=(a[j]-a[i])^(a[k]-a[i]);
                ++c;
                A[c]=o.x;B[c]=o.y;C[c]=o.z;
                D[c]=-o.x*a[i].x-o.y*a[i].y-o.z*a[i].z;
                E[c]=sqrt(A[c]*A[c]+B[c]*B[c]+C[c]*C[c]);
            }
    double d;
    for(i=1;i<=4;i++){
        X=a[i].x;Y=a[i].y;Z=a[i].z;
        d=SA();//d=SA();d=SA();d=SA();d=SA();
        ans=min(d,ans);
    }
    if(ans<eps) printf("O O O O\n");
    else printf("%.4f %.4f %.4f %.4f\n",X,Y,Z,ans);
}

int main()
{
    int tmp;
    while(~scanf("%lf%lf%lf",&a[1].x,&a[1].y,&a[1].z)) fuck();
 return 0;
}
