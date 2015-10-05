#include<stdio.h>

int main()
{
	long long ans=0,b[100003]={0},n,i,x,max=0,a[100003]={0};
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		x=100000;
		//scanf("%d",&x);
		a[x]++;
		if(x>max) max=x;
	}
	for(i=max;i>=1;i--){
		b[i]=(b[i+2]>b[i+3]?b[i+2]:b[i+3])+a[i]*i;
		if(b[i]>ans) ans=b[i];
	}
	printf("%lld\n",ans);
 return 0;
}

