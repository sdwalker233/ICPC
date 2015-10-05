#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,g[210][210],from[210],use[210],tot;

bool hungary(int x)
{
	int i;
	for(i=1+m;i<=m+n;i++){
		if(g[x][i]==0) continue;
		if(!use[i]){
			use[i]=true;
			if(from[i]==-1||hungary(from[i])){
				from[i]=x;
				return true;
			}
		}
	}
	return false;
}

void fuck()
{
	int i,k,j,x;
	memset(g,0,sizeof(g));
	for(i=1;i<=m;i++){
		scanf("%d",&k);
		for(j=1;j<=k;j++){
			scanf("%d",&x);
			g[i][x+m]=1;
		}
	}
	tot=0;
	memset(from,-1,sizeof(from));
	for(i=1;i<=m;i++){
		memset(use,0,sizeof(use));
		if(hungary(i)) ++tot;
	}
	printf("%d\n",tot);
}
int main()
{
	while(~scanf("%d%d",&n,&m)){
		fuck();
	}
 return 0;
}