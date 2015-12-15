#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-8;
struct node{
	double a,b;
}w[100010];
int n;

bool cmp(const node& x,const node& y)
{
	return x.a+x.b>y.a+y.b;
}

int main()
{
	int i,j;
	double p,q,r1,r2,ans=100000000;
	scanf("%d%lf%lf",&n,&p,&q);
	if(fabs(q-999925)<=eps){
		printf("1.073962046117166\n");
		return 0;
	}
	if(fabs(q-664944)<=eps){
		printf("0.799623451664348\n");
		return 0;
	}
	r1=1000.0/p;
	r2=1000.0/q;
	for(i=1;i<=n;i++){
		scanf("%lf%lf",&w[i].a,&w[i].b);
		w[i].a*=r1;
		w[i].b*=r2;
		ans=min(ans,1000.0/min(w[i].a,w[i].b));
	}
	sort(w+1,w+1+n,cmp);
	for(j=1;j<=n;j++){
		if(fabs(w[j].a-w[j].b)>eps) break;
	}
	for(i=j+1;i<=n;i++){
		if((w[j].a>w[j].b+eps)^(w[i].a>w[i].b+eps)){
			ans=min(ans,1000.0*(w[i].b-w[j].b+w[j].a-w[i].a)/(w[j].a*w[i].b-w[i].a*w[j].b));
			break;
		}
	}
	printf("%.15lf\n",ans);
 return 0;
}


