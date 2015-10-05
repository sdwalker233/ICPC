#include<stdio.h>
#define N 21617
int b[3]={23,28,33};

 void run(int a[],int t,int d){
 	int i,j,ok[2][N]={0};
 	for(i=0;i<=2;i++)
 		a[i]%=b[i];
 	for(i=0;i<=1;i++)
 		for(j=a[i];j<N;j+=b[i])
 			ok[i][j]=1;
 	for(i=a[2];i<N;i+=b[2])
 		if(i>d&&ok[0][i]==1&&ok[1][i]==1){
		 	printf("Case %d: the next triple peak occurs in %d days.\n",t,i-d);
		 	break;
		 }
 }

int main()
{
	int i=1,a[3],d;
	while(1){
		scanf("%d%d%d%d",&a[0],&a[1],&a[2],&d);
		if(a[0]==-1&&a[1]==-1&&a[2]==-1&&d==-1) break;
		run(a,i,d);
		i++;
	}
 return 0;
}

