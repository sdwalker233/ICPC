#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100010],b[100010];

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		b[i]=a[i]+a[i+1];
		cout<<b[i]<<" ";
	}
 return 0;
}

