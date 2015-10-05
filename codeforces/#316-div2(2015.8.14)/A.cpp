#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n,m,a[110][110],i,j,city[110],max,maxi,p[110]={0};
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=m;i++){
		max=-1;
		for(j=1;j<=n;j++)
			if(a[i][j]>max){
				max=a[i][j];
				maxi=j;
			}
		p[maxi]++;
	}
	max=-1;
	for(i=1;i<=n;i++){
		if(p[i]>max){
			max=p[i];
			maxi=i;
		}
	}
	printf("%d\n",maxi);
 return 0;
}


