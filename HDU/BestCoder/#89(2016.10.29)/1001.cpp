#include <bits/stdc++.h>
using namespace std;
char s[10010];

void fuck()
{
	int l,i,j;
	int cnt=0;
	scanf("%s",s+1);
	l=strlen(s+1);
	for(i=1;i<=l;i++)
		for(j=2;i*j*j<=l;j++){
			if(s[i]=='y'&&s[i*j]=='r'&&s[i*j*j]=='x') ++cnt;
			if(s[i]=='x'&&s[i*j]=='r'&&s[i*j*j]=='y') ++cnt;
	}
	printf("%d\n",cnt);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

