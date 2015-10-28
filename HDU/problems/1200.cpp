#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,l;
char s[500],a[210][210];

void fuck()
{
	int i,j,cnt=0;
	scanf("%s",s+1);
	l=strlen(s+1);
	m=l/n;
	for(i=1;i<=m;i++){
		if(i%2)
			for(j=1;j<=n;j++)
				a[i][j]=s[++cnt];
		else
			for(j=n;j>=1;j--)
				a[i][j]=s[++cnt];
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			printf("%c",a[j][i]);
	puts("");
}

int main()
{
	while(~scanf("%d",&n)&&n)
		fuck();
 return 0;
}