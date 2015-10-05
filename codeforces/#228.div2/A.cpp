#include<bits/stdc++.h>
int gcd(int x,int y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
}

int main()
{
	int n,i,a[1010],ans,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ans=a[1];
	for(i=2;i<=n;i++) ans=gcd(ans,a[i]);
	printf("%d",n*ans);
 return 0;
}
