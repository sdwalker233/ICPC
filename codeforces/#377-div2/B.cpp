#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,a[510],i;
	int sum=0,b[510]={0};
	cin>>n>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	b[1]=a[1];
	for(i=2;i<=n;i++){
		if(a[i]+b[i-1]<k) b[i]=k-b[i-1];
		else b[i]=a[i];
		sum+=b[i]-a[i];
	}
	printf("%d\n",sum);
	for(i=1;i<=n;i++) printf("%d ",b[i]);
 return 0;
}

