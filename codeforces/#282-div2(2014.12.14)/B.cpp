#include<stdio.h>
#include<math.h>

int main()
{
	int a,b,ans=0,i;
	scanf("%d%d",&a,&b);
	a=a-b;
	if(a==0){
		printf("infinity\n");
		return 0;
	}
	for(i=1;i<=sqrt(a);i++)
		if(a%i==0){
			ans+=2;
			if(i<=b) ans--;
			if(a/i<=b) ans--;
		}
	if((int)sqrt(a)*(int)sqrt(a)==a&&b<sqrt(a)) ans--;
	printf("%d\n",ans);
 return 0;
}

