#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
unsigned long long n,m;

int fuck()
{
	int i;
	unsigned long long x,ans=0,tmp1,tmp2,a;
	scanf("%I64u%I64u",&n,&m);
	x=sqrt((double)n+0.5);
	for(i=2;i<=x&&n!=1;i++){
		if(n%i&&m%i) continue;
		if(n%i||m%i) return -1;
		tmp1=tmp2=0;
		while(n%i==0){
			n/=i;
			tmp1++;
		}
		while(m%i==0){
			m/=i;
			tmp2++;
		}
		if(tmp2<tmp1) return -1;
		a=0;
		while(tmp1<tmp2){
			tmp1<<=1;
			a++;
		}
		ans=max(ans,a);
	}
	if(n>1){
		if(m%n) return -1;
		tmp2=0,tmp1=1;
		while(m%n==0){
			m/=n;
			tmp2++;
		}
		a=0;
		while(tmp1<tmp2){
			tmp1<<=1;
			a++;
		}
		ans=max(ans,a);
	}
	if(m!=1) return -1;
	return ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		printf("%d\n",fuck());
 return 0;
}

