#include<stdio.h>
#define MAX 10
#define p 9973
struct Mat{
	int m[MAX+1][MAX+1];
};
int n,k;
Mat E,A;

 void matprint(Mat A)
 {
 	int i,j;
 	for(i=1;i<=n;i++){
 		for(j=1;j<=n;j++)
 			printf("%d ",A.m[i][j]);
 		printf("\n");
 	}
 }

 Mat matMultiply(Mat A,Mat B)
 {
 	int i,j,k;
 	Mat temp;
 	for(i=1;i<=n;i++)
 		for(j=1;j<=n;j++){
 			temp.m[i][j]=0;
 			for(k=1;k<=n;k++){
 				temp.m[i][j]+=A.m[i][k]*B.m[k][j]%p;
 				temp.m[i][j]%=p;
 			}
 		}
 	return temp;
 }

 Mat matQuickPow(Mat A,int n)
 {
 	Mat temp=E;
 	while(n){
 		if(n&1) temp=matMultiply(A,temp);
 		n>>=1;
 		A=matMultiply(A,A);
 	}
 	return temp;
 }

 int find_tr(Mat A)
 {
 	int i,sum=0;
 	for(i=1;i<=n;i++){
 		sum+=A.m[i][i];
 		sum%=p;
 	}
 	return sum;
 }

int main()
{
	int i,j,t,s;
	scanf("%d",&t);
	for(i=1;i<=MAX;i++)
		E.m[i][i]=1;
	for(s=1;s<=t;s++){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&A.m[i][j]);
		A=matQuickPow(A,k);
		//matprint(A);
		printf("%d\n",find_tr(A));
	}
 return 0;
}

