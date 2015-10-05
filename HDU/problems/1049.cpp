#include<stdio.h>

int main()
{
	int n,u,d,ans;
	while(scanf("%d%d%d",&n,&u,&d)&&n){
		ans=(n-u)/(u-d)*2+1;
		if((n-u)%(u-d)) ans+=2;
		printf("%d\n",ans);
	}
 return 0;
}

