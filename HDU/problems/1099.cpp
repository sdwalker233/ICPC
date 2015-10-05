#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

 long long gcd(long long x,long long y)
 {
 	if(y==0) return x;
 	return gcd(y,x%y);
 }

int main()
{
	int i,n,len1[30],len2[30],r[30];
	long long p[30],q[30],t;
	p[1]=q[1]=1;
	for(i=2;i<=22;i++){
		p[i]=p[i-1]*i+q[i-1];
		q[i]=q[i-1]*i;
		t=gcd(p[i],q[i]);
		p[i]/=t;q[i]/=t;
	}
	for(i=1;i<=22;i++){
		p[i]*=i;
		t=gcd(p[i],q[i]);
		p[i]/=t;q[i]/=t;
		r[i]=p[i]/q[i];
		p[i]%=q[i];
		len1[i]=(int)log10((double)r[i])+1;
		len2[i]=(int)log10((double)q[i])+1;
		//printf("%lld %lld %lld\n",r[i],p[i],q[i]);
	}
	while(~scanf("%d",&n)){
		if(p[n]==0){
			printf("%d\n",r[n]);
			continue;
		}
		for(i=1;i<=len1[n]+1;i++)
			printf(" ");
		printf("%lld\n",p[n]);
		printf("%d ",r[n]);
		for(i=1;i<=len2[n];i++)
			printf("-");
		printf("\n");
		for(i=1;i<=len1[n]+1;i++)
			printf(" ");
		printf("%lld\n",q[n]);
	}
 return 0;
}

