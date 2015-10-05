#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n,m,a[51],b[51],i,j,p=0,cnt=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)	scanf("%d",&a[i]);
	scanf("%d",&m);
	for(i=1;i<=m;i++)	scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(b[j]%a[i]==0) p=max(p,b[j]/a[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(b[j]%a[i]==0&&b[j]/a[i]==p) cnt++;
	cout<<cnt;
 return 0;
}

