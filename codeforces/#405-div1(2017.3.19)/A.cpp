#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,a[100];
	string s[100];
	int i,j;
	cin>>n>>k;
	for(i=1;i<=n-k+1;i++) cin>>s[i];
	for(i=1;i<=n;i++) a[i]=i;
	for(i=1;i<=n-k+1;i++){
		if(s[i]=="NO") a[i+k-1]=a[i];
	}
	for(i=1;i<=n;i++){
		printf("%c%c\n",'A'+a[i]/10,'a'+a[i]%10);
	}
 return 0;
}

