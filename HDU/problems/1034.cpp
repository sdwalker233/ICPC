#include<stdio.h>
int n,a[1000001];

 void run()
 {
 	int i,j,tmp1,tmp2;
 	for(i=1;i<=n;i++)
 		scanf("%d",&a[i]);
 	for(i=1;;i++){
 		tmp1=a[n]>>1;
 		for(j=1;j<=n;j++){
 			tmp2=a[j]>>1;
 			a[j]>>=1;
 			a[j]+=tmp1;
 			tmp1=tmp2;
 			if(a[j]%2) a[j]++;
 		}
 		for(j=2;j<=n;j++)
 			if(a[j]!=a[1]) break;
 		if(j>n){
 			printf("%d %d\n",i,a[1]);
 			return;
 		}
 	}
 }

int main()
{
	while(scanf("%d",&n)!=EOF&&n)
		run();
 return 0;
}

