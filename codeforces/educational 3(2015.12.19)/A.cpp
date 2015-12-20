#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,a[110],sum=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		sum+=a[i];
		if(sum>=m){
			cout<<n-i+1;
			return 0;
		}
	}
 return 0;
}


