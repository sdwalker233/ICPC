#include<stdio.h>

int main()
{
	int n,m,ans=0,t;
	scanf("%d%d",&n,&m);
	while(n&&m&&n+m>=3){
		if(n<m){
			n--;m-=2;
		}
		else{
			n-=2;m--;
		}
		ans++;
	}
	printf("%d\n",ans);
 return 0;
}

