#include<bits/stdc++.h>
using namespace std;
long long a[20]={0};

int main()
{
	int n,m,x,i,j;
	long long ans=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		a[x]++;
	}
	for(i=1;i<=m;i++)
		for(j=i+1;j<=m;j++){
			ans+=a[i]*a[j];
		}
	cout<<ans;
 return 0;
}
