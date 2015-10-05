#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1010],n,q;
int b[1010][1010]={0},c[1010][1010]={0},ans[1010][1010]={0};
long long cnt;

void fuck()
{
	int i,j;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(a[i]>a[j]) b[i][j]=b[i][j-1]+1;
			else b[i][j]=b[i][j-1];
		}
	}
	for(j=1;j<=n;j++){
		for(i=1;i<=j;i++){
			c[j][i]=c[j][i-1]+b[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			ans[i][j]=c[j][j]-c[j][i-1];
		}
	}
}

int main()
{
	int l,r;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	fuck();
	for(int i=1;i<=q;i++){
		scanf("%d%d",&l,&r);
		cnt=0;
		printf("%d\n",ans[l][r]);
	}
 return 0;
}

