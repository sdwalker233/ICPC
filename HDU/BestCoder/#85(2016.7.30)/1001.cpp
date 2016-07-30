#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;
int n,m;
int b[MAXN];

bool fuck()
{
	int i,x,sum=0;
	int f=0;
	memset(b,0,sizeof(b));
	scanf("%d%d",&n,&m);
	b[0]=1;
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		sum+=x;sum%=m;
		//printf(" %d\n",sum);
		if(b[sum]==1) f=1;
		b[sum]=1;
	}
	return f;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0){
		if(fuck()) printf("YES\n");
		else printf("NO\n");
	}
 return 0;
}

