#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX=(1<<30);
const double eps=1e-10;
double dis[10010];

long long fuck()
{
	double x;
	int i;
	long long ans=0;
	scanf("%lf",&x);
	if(fabs(0.5-x)<eps) return 1002;
	x=(MAX/2)-x*MAX;
	for(i=1;i<=500;i++){
		if(fabs(dis[i]-x)<eps) return -1;
		if(dis[i]<x) break;
		ans+=4;
	}
	//printf("%lf\n",dis[i]);
	return ans;
}

int main()
{
	int i;
	dis[0]=MAX;
	for(i=1;i<=500;i++)
		dis[i]=dis[i-1]/2;
	int t;
	scanf("%d",&t);
	while(t-->0)
		printf("%lld\n",fuck());
 return 0;
}

