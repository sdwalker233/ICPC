#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[3146000];

bool fuck()
{
	char s0[5]={'w','y','h'},last=0;
	int find=0,i,l;
	scanf("%s",s+1);
	l=strlen(s+1);
	for(i=1;i<=l;i++){
		if(s[i]=='v'&&last=='v') s[i]='w';
		else last=s[i];
		if(s[i]==s0[find]) find++;
		if(find>2) return 1;
	}
	return 0;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		if(fuck()) printf("Yes\n");
		else printf("No\n");
 return 0;
}

