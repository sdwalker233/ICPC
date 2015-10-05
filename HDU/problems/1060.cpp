#include<stdio.h>
#include<math.h>
int main()
{
	int t,n,i;
	double p;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		p=n*log10((double)n)+1;
		for(i=2;i<=10;i++)
			if((long long)(p-log10((double)i))!=(long long)p) break;
		printf("%d\n",i-1);
	}
 return 0;
}

