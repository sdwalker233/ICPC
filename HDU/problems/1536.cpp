#include <bits/stdc++.h>
using namespace std;
int n,s[110],SG[10010],m,l;

void fuck()
{
	int i,j;
	bool vis[110];
	for(i=1;i<=n;i++)
		scanf("%d",&s[i]);
	for(i=1;i<=10000;i++){
		memset(vis,0,sizeof(vis));
		for(j=1;j<=n;j++){
			if(i<s[j]) continue;
			vis[SG[i-s[j]]]=1;
		}
		for(j=0;j<=n+1;j++)
			if(vis[j]==0) break;
		SG[i]=j;
	}
	int tmp,x;
	scanf("%d",&m);
	while(m-->0){
		tmp=0;
		scanf("%d",&l);
		while(l-->0){
			scanf("%d",&x);
			tmp^=SG[x];
		}
		if(tmp) printf("W");
		else printf("L");
	}
	puts("");
}

int main()
{
	while(~scanf("%d",&n)&&n) fuck();
 return 0;
}

