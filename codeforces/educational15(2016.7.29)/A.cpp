#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a[100010],i,cnt=0,mx=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=0x7fffffff;cnt=1;
	for(i=1;i<=n;i++){
		if(a[i]>a[i-1]){
			cnt++;
			mx=max(mx,cnt);
		}
		else{
			cnt=1;
		}
	}
	cout<<mx<<endl;
 return 0;
}

