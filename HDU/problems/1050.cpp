#include<stdio.h>

 void run()
 {
 	int num[201]={0},a,b,n,i,j,tmp,ans=0;
 	scanf("%d",&n);
 	for(i=1;i<=n;i++){
 		scanf("%d%d",&a,&b);
 		if(a>b){
 			tmp=a;
 			a=b;
 			b=tmp;
 		}
 		for(j=(a+1)/2;j<=(b+1)/2;j++)
 			num[j]++;
 		}
 	for(i=1;i<=200;i++)
 		if(num[i]>ans) ans=num[i];
 	printf("%d\n",ans*10);
 }

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		run();
 return 0;
}

