#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double ttt=1.0/pow(2,1.0/3);
int a[10010],h[10010],n;
double sumv;

bool check(int x)
{
	int i;
	double sum=0;
	for(i=1;i<=n;i++){
		if(h[i]<=x) sum+=h[i]*a[i];
		else sum+=(double)(h[i]*a[i])-(double)(h[i]-x)*(h[i]-x)*(h[i]-x)/h[i]/h[i]*a[i];
	}
	return sum*2>sumv;
}
void fuck()
{
	int i,ans=0;
	sumv=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&h[i]);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]*=a[i];
		sumv+=(double)a[i]*h[i];
	}

	int l=0,r=1000,m;
	while(l<r){
		m=(l+r)>>1;
		if(check(m)) r=m-1;
		else{
			//printf(" %d\n",m);
			ans=m;
			l=m+1;
		}
	}
	if(check(ans+1)==0) ans++;
	printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}


