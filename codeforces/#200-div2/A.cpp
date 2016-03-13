#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[100010]={0};

int main()
{
	int n,i,cnt=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=a[i-1]) cnt++;
	}
	printf("%d\n",cnt);
 return 0;
}