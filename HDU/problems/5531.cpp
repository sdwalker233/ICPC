#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const double eps=1e-8;
const double pi=acos(-1);
int n,x[10010],y[10010],a[10010];
double r[10010],sum;

bool gao(double x)
{
	int i;
	sum=x*x;
	r[1]=x;
	if(r[1]<-eps) return 0;
	for(i=2;i<=n;i++){
		r[i]=a[i-1]-r[i-1];
		if(r[i]<-eps) return 0;
		sum+=r[i]*r[i];
	}
	if((int)(r[1]+r[n]+0.5)!=a[n]) return 0;
	return 1;
}

void fuck()
{
	int i;
	double L=0,R=0xfffffffffffffff;
	int v=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	x[n+1]=x[1];y[n+1]=y[1];
	for(i=1;i<=n;i++){
		a[i]=(int)(hypot(x[i]-x[i+1],y[i]-y[i+1])+0.5);
		if(i%2) v+=a[i];
		else v-=a[i];
	}
	if(n%2){
		r[1]=(double)v/2;
		if(!gao(r[1]))	printf("IMPOSSIBLE\n");
		else{
			printf("%.2lf\n",sum*pi);
			for(i=1;i<=n;i++) printf("%.2lf\n",r[i]);
		}
		return;
	}
	if(v){
		printf("IMPOSSIBLE\n");
		return;
	}
	double k=0,ll,rr,mid,midmid,res1,res2;
	a[0]=a[n];
	for(i=1;i<=n;i++){
		ll=0;rr=min(a[i],a[i-1]);
		if(i%2){
			L=max(L,ll-k);
			R=min(R,rr-k);
		}
		else{
			L=max(L,k-rr);
			R=min(R,k-ll);
		}
		k=a[i]-k;
	}
	if(L>R){
		printf("IMPOSSIBLE\n");
		return;
	}
	ll=L;rr=R;
	for(i=1;i<=50;i++){
		mid=(L+R)/2;
		midmid=(mid+R)/2;
		gao(mid);res1=sum;
		gao(midmid);res2=sum;
		if(res1<res2) R=midmid;
		else L=mid;
	}
	gao(L);
	printf("%.2f\n",sum*pi);
	for(i=1;i<=n;i++) printf("%.2lf\n",r[i]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}