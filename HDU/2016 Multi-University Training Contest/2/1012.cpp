#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s1[100010],s2[5010];
int n,m,ans[100010];

void fuck()
{
	int i,j,tot=0;
	scanf("%d%d",&n,&m);
	scanf("%s%s",s1,s2);
	for(i=0;i+m<=n;i++){
		for(j=0;j<m;j++){
			if(s1[i+j]!=s2[j]){
				if(s1[i+j+1]==s2[j]&&s1[i+j]==s2[j+1]) j++;
				else break;
			}
		}
		if(j>=m) ans[++tot]=i;
	}
	//for(i=1;i<=tot;i++) printf(" %d",ans[i]);
	ans[++tot]=n+1;
	j=1;
	for(i=0;i<n;i++){
		if(i==ans[j]){
			putchar('1');
			j++;
		}
		else putchar('0');
	}
	puts("");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

