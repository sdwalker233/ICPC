#include <bits/stdc++.h>
using namespace std;
int n,k,a[110];

int f(int x)
{
	int m=(x/k)-(x%k==0);
	return x+m*5;
}

int main()
{
	int i;
	cin>>n>>k;
	string s;
	for(i=1;i<=n;i++){
		cin>>s;
		a[s.length()]++;
	}
	cin>>s;
	int l=s.length();
	int sum=0;
	for(i=1;i<l;i++)
		sum+=a[i];
	printf("%d %d\n",f(sum+1),f(sum+a[l]));
 return 0;
}

