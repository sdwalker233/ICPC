#include<stdio.h>
#include<string.h>
int n,a[10000001];

 void run(){
 	int i,x,ans,max=0;
 	memset(a,0,sizeof(a));
 	for(i=1;i<=n;i++){
 		scanf("%d",&x);
 		a[x]++;
 	}
 	for(i=0;i<=10000000;i++)
 		if(a[i]>=(n+1)/2){
 			printf("%d\n",i);
 			break;
 		}
 }

int main()
{
	while(scanf("%d",&n)!=EOF)
		run();
 return 0;
}

