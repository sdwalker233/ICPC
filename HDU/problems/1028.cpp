//母函数：(1+x+x^2+x^4...)(1+x^2+x^4+x^6...)(1+x^3+x^6+x^9...)(...)
#include<stdio.h>
#define maxn 120
int n;

int main()
{
	int i,j,k,c1[1000],c2[1000],n;
 	for(i=0;i<=maxn;i++){
 		c1[i]=1;
 		c2[i]=0;
 	}
 	for(i=2;i<=maxn;i++){
 		for(j=0;j<=maxn;j++)
 			for(k=0;k+j<=maxn;k+=i)
 				c2[k+j]+=c1[j];
 		for(j=0;j<=maxn;j++){
 			c1[j]=c2[j];
 			c2[j]=0;
 		}
 	}
 	while(scanf("%d",&n)!=EOF)
 		printf("%d\n",c1[n]);
 return 0;
}

