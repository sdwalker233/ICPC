#include <bits/stdc++.h>
using namespace std;
int SG[1010];
bool vis[2010];

int main()
{
	int i,j;
	for(i=1;i<=100;i++){
		memset(vis,0,sizeof(vis));
		for(j=1;j<i;j++){
			vis[SG[j]]=1;
			vis[SG[j]^SG[i-j]]=1;
		}
		for(j=0;j<=2*i;j++)
			if(vis[j]==0) break;
		SG[i]=j;
		printf("SG[%d]=%d\n",i,SG[j]);
	}
 return 0;
}

