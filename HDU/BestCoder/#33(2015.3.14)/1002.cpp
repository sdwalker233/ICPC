#include<stdio.h>

 long long QuickPlus(long long a,long long b,long long p)
 {
 	long long ans=0;
 	while(b){
 		if(b&1){
 			ans+=a;
 			if(ans>=p) ans-=p;
 		}
 		a=a<<1;
 		if(a>=p) a-=p;
 		b>>=1;
 	}
 	return ans;
 }

 long long QuickPow(long long a,long long b,long long p)
 {
 	long long ans=1;
 	a%=p;
 	while(b){
 		if(b&1) ans=QuickPlus(a,ans,p);
 		a=QuickPlus(a,a,p)%p;
 		b>>=1;
 	}
 	return ans;
 }

int main()
{
	long long n,p;
	while(scanf("%I64d%I64d",&n,&p)!=EOF){
		if(n==1) printf("%I64d\n",1%p);
		else printf("%I64d\n",(QuickPow(2ll,n,p)+p-2)%p);
	}
 return 0;
}

