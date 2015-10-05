#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,c,a[110][110];

void fuck()
{
	int i,j;
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&c);
	for(i=1;i<=n;i++)
		scanf("%d",&a[1][i]);
	for(i=2;i<=n;i++){
		for(j=i;j<=n;j++){
			a[i][j]=a[i-1][j]-a[i-1][j-1];
		}
	}
	for(i=n+1;i<=n+c;i++)
		a[n][i]=a[n][n];
	for(i=n-1;i>=1;i--)
		for(j=n+1;j<=n+c;j++)
			a[i][j]=a[i][j-1]+a[i+1][j];
	for(i=n+1;i<n+c;i++)
		printf("%d ",a[1][i]);
	printf("%d\n",a[1][i]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		fuck();
 return 0;
}


