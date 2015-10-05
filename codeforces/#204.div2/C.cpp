#include<bits/stdc++.h>
#define eps 1e-8
using namespace std;

int main()
{
	int n,i,cnt=0;
	double x,sum=0,ans;
	scanf("%d",&n);
	for(i=1;i<=2*n;i++){
		scanf("%lf",&x);
		x=x-(int)x;
		if(x<eps) cnt++;
		else sum+=x;
	}
	sum-=n;
	ans=fabs(sum);
	for(i=1;i<=min(n,cnt);i++){
		sum+=1;
		ans=min(ans,fabs(sum));
	}
	printf("%.3lf",ans);
 return 0;
}

