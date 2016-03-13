#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int nxt[5010],fr[5010];
bool vis[5010];

void fuck()
{
	int i,cur;
	memset(vis,0,sizeof(vis));
	//scanf("%d",&n);
	for(i=1;i<=n;i++){
		fr[i]=i-1;
		nxt[i]=i+1;
	}
	fr[1]=n;nxt[n]=1;cur=n;
	for(int t=1;t<n;t++){
		for(i=1;i<=t;i++)
			cur=nxt[cur];
		nxt[fr[cur]]=nxt[cur];
		fr[nxt[cur]]=fr[cur];
		vis[cur]=1;
	}
	for(i=1;i<=n;i++)
		if(vis[i]==0) break;
	//printf("%d\n",i);
	printf("%d,",i);
}

int main()
{
	freopen("out.txt","w",stdout);
	int t;
	//scanf("%d",&t);
	//while(t-->0) fuck();
	for(n=1;n<=5000;n++)
		fuck();
 return 0;
}