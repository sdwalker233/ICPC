#include<iostream>
#include<cstdio>
using namespace std;
int n,a[110][110];

 void run()
 {
 	int i,j,k,sum[110][110]={0},b[110],mx1=-0x80000000,mx=0,s;
 	for(i=1;i<=n;i++)
 		for(j=1;j<=n;j++){
 			scanf("%d",&a[i][j]);
 			mx1=max(mx1,a[i][j]);
 			sum[i][j]=sum[i][j-1]+a[i][j];
 		}
 	for(i=1;i<=n;i++){
 		for(j=i;j<=n;j++){
 			for(k=1;k<=n;k++)
 				b[k]=sum[k][j]-sum[k][i-1];
 			s=0;
 			for(k=1;k<=n;k++){
 				s+=b[k];
 				if(s>0) mx=max(s,mx);
 				else s=0;
 			}
 		}
 	}
 	if(mx!=0) printf("%d\n",mx);
 	else printf("%d\n",mx1);
 }

int main()
{
	while(~scanf("%d",&n))
		run();
 return 0;
}

