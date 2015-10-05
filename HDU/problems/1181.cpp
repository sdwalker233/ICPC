#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int g[30][30]={0};

void fuck()
{
	int i,j,k;
	for(k=1;k<=26;k++)
		for(i=1;i<=26;i++)
			for(j=1;j<=26;j++)
				if(g[i][k]&&g[k][j]) g[i][j]=1;
	if(g['b'-'a'+1]['m'-'a'+1]) printf("Yes.\n");
	else printf("No.\n");
}

int main()
{
	char s[10000];
	while(~scanf("%s",s+1)){
		if(strcmp(s+1,"0")==0){
			fuck();
			memset(g,0,sizeof(g));
		}
		else{
			int l=strlen(s+1);
			g[s[1]-'a'+1][s[l]-'a'+1]=1;
		}
	}
 return 0;
}