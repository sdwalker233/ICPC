#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,l;
bool a[32][310],ok;
int vis[32];

void DFS(int x)
{
	int i,j,p;
	if(ok) return;
	for(p=1;p<=n;p++)
		if(!vis[p]) break;
	if(p>n){
		ok=1;
		return;
	}
	if(x>l) return;
	for(i=1;i<=300;i++){
		if(a[p][i]==0) continue;
		for(j=1;j<=n;j++){
			if(vis[j]) continue;
			if(a[j][i]==0) continue;
			vis[j]=x;
		}
		DFS(x+1);
		for(j=1;j<=n;j++){
			if(vis[j]==x) vis[j]=0;
		}
	}
}

void fuck()
{
	int i,j,p,x;
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&l);
	for(i=1;i<=n;i++){
		scanf("%d",&p);
		for(j=1;j<=p;j++)
		{
			scanf("%d",&x);
			a[i][x]=1;
		}
	}
	ok=0;
	DFS(1);
	if(ok) printf("YES\n");
	else printf("NO\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}