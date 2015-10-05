#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 210
using namespace std;
int n,m,k;
int g[MAXN][MAXN],from[MAXN],tot;
bool use[MAXN];

bool match(int x)
{
	for(int i=0;i<n+m;i++)
		if(g[x][i]){
			if(!use[i]){
				use[i]=1;
				if(from[i]==-1||match(from[i])){
					from[i]=x;
					return 1;
				}
			}
		}
	return 0;
}

int hungary()
{
	tot=0;
	memset(from,-1,sizeof(from));
	for(int i=0;i<n;i++){
		memset(use,0,sizeof(use));
		if(match(i)){
			++tot;
			//printf("%d\n",i);
		}
	}
	return tot;
}

void fuck()
{
	int i,t,x,y;
	memset(g,0,sizeof(g));
	for(i=1;i<=k;i++){
		scanf("%d%d%d",&t,&x,&y);
		if(x&&y) g[x][y+n]=1;
	}
	//n+=m-1;
	printf("%d\n",hungary());
}

int main()
{
	while(scanf("%d",&n)&&n){
		scanf("%d%d",&m,&k);
		fuck();
	}
 return 0;
}

