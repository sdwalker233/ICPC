#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int m;

bool fuck()
{
	int i,x,mx=0;
	long long sum=0,match;
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&x);
		mx=max(mx,x);
		sum+=x;
	}
	match=(long long)m*(m-1)/2;
	if(sum!=match*2) return 0;
	if(mx>(m-1)*2) return 0;
	return 1;
}

int main()
{
	int t;
	while(~scanf("%d",&t)){
		while(t-->0)
			if(fuck()) printf("T\n");
			else printf("F\n");
	}
 return 0;
}

