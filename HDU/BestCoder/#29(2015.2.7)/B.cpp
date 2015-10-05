#include<stdio.h>
#define p 10000007
struct mat{
	int m[2][2];
}E,A,B;

 mat MatMultiply(mat A,mat B)
 {
 	mat temp;
	int i,j,k;
 	for(i=0;i<=1;i++)
 		for(j=0;j<=1;j++){
 			temp.m[i][j]=0;
 			for(k=0;k<=1;k++)
 				temp.m[i][j]=((long long)(A.m[i][k]*B.m[k][j])%p+temp.m[i][j])%p;
 		}
 	return temp;
 }

 mat MatQuickPow(mat A,int n){
 	mat temp=E;
 	while(n){
 		if(n&1) temp=MatMultiply(temp,A);
 		n>>=1;
 		A=MatMultiply(A,A);
 	}
 	return temp;
 }

int main()
{
	int i,n,k,sum,max1,max2,a;
	E.m[0][0]=1;E.m[0][1]=0;
	E.m[1][0]=0;E.m[1][1]=1;
	A.m[0][0]=1;A.m[0][1]=1;
	A.m[1][0]=1;A.m[1][1]=0;
	while(scanf("%d%d",&n,&k)!=EOF){
		sum=max1=max2=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a);
			if(a>max1){
				max2=max1;
				max1=a;
			}
			else if(a>max2) max2=a;
			sum+=a;
			sum%=p;
		}
	B=MatQuickPow(A,k+1);
	B.m[0][0]--;B.m[1][1]--;
	B=MatMultiply(B,A);
	sum=(B.m[0][0]*max1%p+B.m[1][0]*max2%p+sum-max1+p)%p;
	printf("%d\n",sum);
	}
 return 0;
}

