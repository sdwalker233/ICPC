#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a[4];
	cin>>a[1]>>a[2]>>a[3];
	sort(a+1,a+4);
	if(a[1]==a[3]){printf("0\n");return 0;}
	if(a[2]==a[3]){cout<<a[2]-1-a[1]<<endl;return 0;}
	cout<<2*a[3]-2-a[1]-a[2]<<endl;
 return 0;
}

