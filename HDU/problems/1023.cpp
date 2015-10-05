#include<stdio.h>
int n;
 void printa(int a[],int len)
 {
 	int i;
 	//printf("%d ",len );
 	for(i=len;i>=1;i--)
		printf("%d",a[i]);
	printf("\n");
 }

 void run()
 {
 	int a[500]={0},i,j,len=1,tmp=0;
	a[1]=1;
 	for(i=n+2;i<=2*n;i++){
		for(j=1;j<=len;j++)
			a[j]*=i;
		for(j=1;j<=len;j++){
			a[j+1]+=a[j]/10;
			a[j]%=10;
		}
		while(a[j]){
			a[j+1]+=a[j]/10;
			a[j]%=10;
			j++;
		}
		len=j-1;
		//printa(a,len);
	}
	for(i=2;i<=n;i++){
		for(j=len;j>=1;j--){
			tmp*=10;
			tmp+=a[j];
			a[j]=tmp/i;
			tmp%=i;
		}
		while(a[len]==0) len--;
	}
	printa(a,len);
 }

int main()
{
	while(scanf("%d",&n)!=EOF)
		run();
 return 0;
}

