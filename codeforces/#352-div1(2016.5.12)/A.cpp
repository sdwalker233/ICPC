#include <bits/stdc++.h>
using namespace std;
struct node{
	double x,y,index;
	double d,da,db;
}a[100010],b[100010];
int n;

bool cmpa(const node& x,const node& y)
{
	return x.da-x.d<y.da-y.d;
}

bool cmpb(const node& x,const node& y)
{
	return x.db-x.d<y.db-y.d;
}

double f(int x1,int y1)
{
	double sum=0;
	bool f=0;
	if(a[x1].da-a[x1].d<=0){
		sum+=a[x1].da-a[x1].d;
		f=1;
	}
	if(b[y1].db-b[y1].d<=0){
		sum+=b[y1].db-b[y1].d;
		f=1;
	}
	if(f==0){
		sum+=min(a[x1].da-a[x1].d,b[y1].db-b[y1].d);
	}
	return sum;
}
int main()
{
	int i;
	int ax,ay,bx,by,tx,ty;
	double sum=0;
	scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&tx,&ty);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lf%lf",&a[i].x,&a[i].y);
		a[i].d=sqrt((a[i].x-tx)*(a[i].x-tx)+(a[i].y-ty)*(a[i].y-ty));
		sum+=a[i].d*2;
		a[i].da=sqrt((a[i].x-ax)*(a[i].x-ax)+(a[i].y-ay)*(a[i].y-ay));
		a[i].db=sqrt((a[i].x-bx)*(a[i].x-bx)+(a[i].y-by)*(a[i].y-by));
		a[i].index=i;
		b[i]=a[i];
	}
	sort(a+1,a+n+1,cmpa);
	sort(b+1,b+n+1,cmpb);
	if(n==1){
		sum+=min(a[1].da,a[1].db)-a[1].d;
	}
	else if(a[1].index!=b[1].index){
		sum+=f(1,1);
	}
	else{
		sum+=min(f(1,2),f(2,1));
	}
	printf("%.15f\n",sum);
 return 0;
}

