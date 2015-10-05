#include<stdio.h>
#include<string.h>
int m,n,v[1000001],a[1000001],last[1000001];

 int max(int a,int b)
 {
 	return a>b?a:b;
 }

 void run()
 {
 	int i,j,max_sum;
 	for(i=1;i<=n;i++)
 		scanf("%d",&v[i]);
 	memset(last,0,sizeof(last));
 	memset(a,0,sizeof(a));
 	for(i=1;i<=m;i++){
 		max_sum=-0x7ffffff;
 		for(j=i;j<=n;j++){
 			a[j]=max(a[j-1],last[j-1])+v[j];
 			last[j-1]=max_sum;
 			max_sum=max(max_sum,a[j]);
 		}
		last[n]=max_sum;
	}
 	printf("%d\n",max_sum);
 }

int main()
{
	while(scanf("%d%d",&m,&n)!=EOF)
		run();
 return 0;
}

