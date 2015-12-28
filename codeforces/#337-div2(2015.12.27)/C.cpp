#include <bits/stdc++.h>
using namespace std;
int n;
int a[12][520][520]={0};

int main()
{
	int i,j,k,size=1;
	scanf("%d",&n);
	a[0][0][0]=1;
	for(k=1;k<=n;k++){
		for(i=0;i<size;i++)
			for(j=0;j<size;j++){
				a[k][i<<1][j]=a[k-1][i][j];
				a[k][i<<1|1][j]=a[k-1][i][j];
			}
		for(i=0;i<size;i++)
			for(j=0;j<size;j++){
				a[k][i<<1][j+size]=a[k-1][i][j];
				a[k][i<<1|1][j+size]=0-a[k-1][i][j];
			}
		size<<=1;
	}
	for(i=0;i<size;i++){
		for(j=0;j<size;j++)
			if(a[n][i][j]==1) putchar('+');
			else putchar('*');
		puts("");
	}
 return 0;
}