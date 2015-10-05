#include<stdio.h>
int A,B,n,a[101];

 void fuck()
 {
 	int i,loop;
 	A%=7;B%=7;
 	a[1]=1;a[2]=1;
 	for(i=3;i<=50;i++){
 		a[i]=(A*a[i-1]+B*a[i-2])%7;
 		if(a[i]==1&&a[i-1]==1) break;
 	}
	loop=i-2;
	a[0]=a[loop];
	printf("%d ",loop);
	printf("%d\n",a[n%loop]);
 }

int main()
{
	while(1){
		scanf("%d%d%d",&A,&B,&n);
		if(!A&&!B&&!n) return 0;
		fuck();
	}
 return 0;
}

