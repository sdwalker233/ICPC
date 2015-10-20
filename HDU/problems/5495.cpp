#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,a[100010],b[100010],nxt[100010];
bool vis[100010];

void run()
{
	memset(vis,0,sizeof(vis));
	int i,len,p,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
		nxt[a[i]]=b[i];
	for(i=1;i<=n;i++){
		if(vis[i]) continue;
		len=0;p=i;
		while(!vis[p]){
			vis[p]=1;
			p=nxt[p];
			len++;
		}
		if(len==1) ans++;
		else ans+=len-1;
	}
	printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		run();
 return 0;
}