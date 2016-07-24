#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const double eps=1e-8;
int n,k;
double p[30],dp[(1<<20)+10];

double fuck(int x)
{
	//if(p[x]<eps) return 0;
	int i,mask,pp=(1<<n);
	double f[30]={0};
	dp[0]=f[0]=p[x];
	for(mask=1;mask<pp;++mask) 
	if((mask&(1<<x))==0){
		dp[mask]=0;
		double rest=1;
		for(i=0;i<n;i++){
			if((mask&(1<<i))){
				dp[mask]+=dp[mask^(1<<i)]*p[i];
				rest-=p[i];
			}
		}
		if(rest>eps) dp[mask]/=rest;
		else dp[mask]=0;
		f[__builtin_popcount(mask)]+=dp[mask];
	}
	double res=0;
	for(i=0;i<k;i++) res+=f[i];
	return res;
}

int main()
{
	int i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%lf",&p[i]);
	}
	for(i=0;i<n;i++){
		printf("%.10f ",fuck(i));
	}
 return 0;
}

