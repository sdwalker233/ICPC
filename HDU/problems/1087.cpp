#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n,i,j,a[1010],mx,dp[1010],ans;
	while(~scanf("%d",&n)&&n){
		ans=-0x80000000;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mx=0;
			for(j=1;j<i;j++)
				if(a[j]<a[i]) mx=max(mx,dp[j]);
			dp[i]=a[i]+mx;
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
 return 0;
}

