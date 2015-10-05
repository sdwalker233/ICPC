#include<iostream>
#include<cstdio>
#include<algorithm>
#define eps 1e-12
using namespace std;

int main()
{
	int t=0;
	double a,b,c,d;
	double l=0,r=1000000000000,m;
	double a1,a2,b1,b2,c1,c2,d1,d2,t1,t2,p1,p2;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	while(t<1000){
		m=(l+r)/2;
		a1=a-m;a2=a+m;
		d1=d-m;d2=d+m;
		t1=min(min(a1*d1,a2*d2),min(a1*d2,a2*d1));
		t2=max(max(a1*d1,a2*d2),max(a1*d2,a2*d1));
		b1=b-m;b2=b+m;
		c1=c-m;c2=c+m;
		p1=min(min(b1*c1,b2*c2),min(b1*c2,b2*c1));
		p2=max(max(b1*c1,b2*c2),max(b1*c2,b2*c1));
		if(t1<p2&&p1<t2) r=m;
		else l=m;
		t++;
	}
	printf("%.10lf\n",l);
 return 0;
}

