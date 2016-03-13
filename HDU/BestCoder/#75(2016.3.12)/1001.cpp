#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void fuck()
{
	int n,m,cnt=0;
	scanf("%d%d",&n,&m);
	if(n<m) swap(n,m);
	while(n&&m){
		cnt+=n/m;
		n%=m;
		swap(n,m);
	}
	if(n&&m&&n==m) cnt++;
	printf("%d\n",cnt);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}