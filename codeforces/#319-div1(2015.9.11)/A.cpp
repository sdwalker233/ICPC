#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool a[1010]={0};

int gcd(int x,int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}

int main()
{
	int i,j,n,cnt=0,ans[1010];
	scanf("%d",&n);
	a[1]=1;
	for(i=2;i<=n;i++){
		if(a[i]) continue;
		ans[++cnt]=i;
		for(j=1;j<=n/i;j++){
			if(a[j]&&gcd(j,i)==1) a[j*i]=1;
		}
	}
	printf("%d\n",cnt);
	for(i=1;i<=cnt;i++)
		printf("%d ",ans[i]);
 return 0;
}


