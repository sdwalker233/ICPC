#include<stdio.h>

void fuck()
{
	long long n;
	int i,j,a[30][30]={0},tmp;
	scanf("%lld",&n);
	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
			a[i][j]=1;
	for(i=11;i<=28;i++)
		a[i][i+1]=1;
	for(i=11;i<=29;i++){
		tmp=n%10;
		for(j=1;j<=tmp;j++)
			a[j][i]=1;
		n/=10;
	}
	printf("29 20\n");
	for(i=1;i<=29;i++){
		for(j=1;j<=29;j++)
			printf("%d",a[i][j]);
		printf("\n");
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		fuck();
 return 0;
}

