#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define eps 1e-6
using namespace std;
int n;
double b[200010],a[200010];

double solve(double x)
{
	int i;
	double mn=1000000000000ll,mx=-1000000000000ll,sum1=0,sum2=0;
	for(i=1;i<=n;i++)
		b[i]=a[i]-x;
	for(i=1;i<=n;i++){
		if(sum1+b[i]>=0){
			sum1+=b[i];
			mx=max(mx,sum1);
		}
		else sum1=0;
		if(sum2+b[i]<=0){
			sum2+=b[i];
			mn=min(mn,sum2);
		}
		else sum2=0;
	}
	//printf("%.2lf %.2lf\n",mx,mn);
	return max(mx,-mn);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i,t=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lf",&a[i]);
	double l=-10000,r=10000,mid,midmid;
	//while(r-l>eps){
	for(t=1;t<=100;t++){
		//t++;
		mid=(l+r)/2;
		midmid=(r+mid)/2;
		if(solve(mid)<=solve(midmid)) r=midmid;
		else l=mid;
	}
	//printf("%d\n",t);
	//for(double p=-10000;p<=10000;p+=10)
		//printf("%.2lf ",p),solve(p);
		//printf("%.2lf %.2lf\n",p,solve(p));
		//printf("%lf\n",l);
	printf("%.10lf\n",solve(l));
 return 0;
}


