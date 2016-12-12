#include <bits/stdc++.h>
using namespace std;
int s[20],SG[1010];

int main()
{
	int i,j;
	bool vis[20];
	s[1]=1;
	for(i=2;i<=16;i++) s[i]=s[i-1]+s[i-2];
	for(i=1;i<=1000;i++){
		memset(vis,0,sizeof(vis));
		for(j=1;j<=16;j++){
			if(i<s[j]) continue;
			vis[SG[i-s[j]]]=1;
		}
		for(j=0;j<=17;j++)
			if(vis[j]==0) break;
		SG[i]=j;
	}
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c)&&(a||b||c)){
		if(SG[a]^SG[b]^SG[c]) printf("Fibo\n");
		else printf("Nacci\n");
	}
 return 0;
}

