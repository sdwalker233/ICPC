#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s1[100000],s2[100000];

bool fuck()
{
	int i,l1,l2;
	bool dot1=0,dot2=0;
	l1=strlen(s1+1);
	l2=strlen(s2+1);
	for(i=1;i<=l1;i++)
		if(s1[i]=='.') dot1=1;
	for(i=1;i<=l2;i++)
		if(s2[i]=='.') dot2=1;
	while(dot1&&(s1[l1]=='0'||s1[l1]=='.')){
		if(s1[l1]=='.') dot1=0;
		l1--;
	}
	while(dot2&&(s2[l2]=='0'||s2[l2]=='.')){
		if(s2[l2]=='.') dot2=0;
		l2--;
	}
	if(l1!=l2) return 0;
	for(i=1;i<=l1;i++){
		if(s1[l1]!=s2[l2]) return 0;
	}
	return 1;
}

int main()
{
	while(~scanf("%s%s",s1+1,s2+1))
		if(fuck()) printf("YES\n");
		else printf("NO\n");	
 return 0;
}