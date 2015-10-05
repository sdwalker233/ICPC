#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MAXN 310
using namespace std;
const double PI=acos(-1);
struct node{
	double ang;
	bool is;
}dot[MAXN>>1];
int n;
double x[MAXN],y[MAXN];

bool cmp(const node& x,const node& y)
{
	return x.ang<y.ang;
}

void fuck()
{
	int i,j,cnt,num,ans=0;
	double dist,tmp,ang;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lf%lf",&x[i],&y[i]);
	}
	for(i=1;i<=n;i++){
		cnt=num=0;
		for(j=1;j<=n;j++){
			if(i==j) continue;
			dist=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))/2;
			if(dist>1) continue;
			ang=acos(dist);
			tmp=atan((y[i]-y[j])/(x[i]-x[j]));
			if(x[j]<x[i]) tmp-=PI;
			if(y[j]>y[i]) tmp=fabs(tmp);
			else tmp=-fabs(tmp);
			cnt++;
			dot[cnt].ang=tmp-ang;
			dot[cnt].is=1;
			cnt++;
			dot[cnt].ang=tmp+ang;
			dot[cnt].is=0;
		}
		sort(dot+1,dot+cnt+1,cmp);
		for(j=1;j<=cnt;j++){
			if(dot[j].is) num++;
			else num--;
			ans=max(num,ans);
		}
	}
	printf("%d\n",ans+1);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}


