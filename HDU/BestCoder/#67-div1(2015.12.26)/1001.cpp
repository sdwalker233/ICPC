#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,g[1010][1010];

bool fuck()
{
	int i,j,sum=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			scanf("%d",&g[i][j]);
			sum+=g[i][j];
		}
	if((n+m-1)%2!=sum%2) return 0;
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		if(fuck()) printf("YES\n");
		else printf("NO\n");
 return 0;
}

