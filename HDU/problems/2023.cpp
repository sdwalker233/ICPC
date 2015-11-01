#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const double eps=1e-8;
int n,m,a[55][10];

void fuck()
{
	int i,j;
	int sum[10]={0},b[55]={0},ans=0,stu[55]={0};
	double aver1[10],aver2[55];
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			sum[j]+=a[i][j];
			stu[i]+=a[i][j];
		}
	}
	for(i=1;i<=m;i++)
		aver1[i]=(double)sum[i]/n;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]-aver1[j]>-eps) b[i]++; 
		}
	}
	for(i=1;i<=n;i++){
		if(b[i]==m) ans++;
		aver2[i]=(double)stu[i]/m;
	}
	for(i=1;i<n;i++)
		printf("%.2lf ",aver2[i]);
	printf("%.2lf\n",aver2[n]);
	for(i=1;i<m;i++)
		printf("%.2lf ",aver1[i]);
	printf("%.2lf\n",aver1[m]);
	printf("%d\n\n",ans);
}

int main()
{
	while(~scanf("%d%d",&n,&m))
		fuck();
 return 0;
}