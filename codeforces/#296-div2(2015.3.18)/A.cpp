#include<stdio.h>

int main()
{
	long long a,b,t,ans=0;
	scanf("%I64%I64",&a,&b);
	if(a<b){
		t=a;
		a=b;
		b=t;
	}
	while(a&&b){
		ans+=a/b;
		t=b;
		b=a%b;
		a=t;
	}
	printf("%I64\n",ans);
 return 0;
}

