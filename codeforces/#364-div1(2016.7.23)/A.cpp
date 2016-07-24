#include <bits/stdc++.h>
using namespace std;
int n,l,v1,v2,k;

bool check(double t)
{
	if(t*v1>=l) return 1;
	int i;
	double t1=(l-t*v1)/(v2-v1);
	double t11=2*t1*v2/(v1+v2);
	double tt=(n-1)*(t11);
	if(tt*v1+(t-tt)*v2>=l) return 1;
	return 0;
}

int main()
{
	int i;
	scanf("%d%d%d%d%d",&n,&l,&v1,&v2,&k);
	n=(n-1)/k+1;
	double left=0,right=1000000010,mid,ans;
	for(i=1;i<=100;i++){
		mid=(left+right)/2;
		//printf(" %lf",mid);
		if(check(mid)){
			right=mid;
			ans=mid;
		}
		else left=mid;
	}
	printf("%.10f\n",ans);
 return 0;
}

