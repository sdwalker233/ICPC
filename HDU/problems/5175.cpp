#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long a[10000],cnt;

 long long gcd(long long x,long long y)
 {
 	if(y==0) return x;
 	return gcd(y,x%y);
 }

int main()
{
	long long n;
	long long i,t=0,p;
	while(scanf("%I64d",&n)!=EOF){
		cnt=0;p=sqrt((double)n);
		if(p*p==n){
			if(p==(n^p)) a[++cnt]=p;
			p--;
		}
		for(i=p;i>=1;i--)
			if(n%i==0){
				if(gcd(n,n-i)==(n^(n-i))) a[++cnt]=n-i;
				if(gcd(n,n-n/i)==(n^(n-n/i))) a[++cnt]=n-n/i;
			}
		sort(a+1,a+cnt+1);
		printf("Case #%I64d:\n",++t);
		if(cnt==0||cnt==1){
			printf("0\n\n");
			continue;
		}
		printf("%I64d\n",cnt-1);
		for(i=2;i<cnt;i++)
			printf("%I64d ",a[i]);
		printf("%I64d\n",a[cnt]);
	}
 return 0;
}

