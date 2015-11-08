#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[100010],t[100010];

bool fuck()
{
	int l1,l2,i,j=1,n1=1,n2=1;
	scanf("%s%s",s+1,t+1);
	l1=strlen(s+1);
	l2=strlen(t+1);
	if(s[1]!=t[1]) return 0;
	while(n1<l1&&s[n1+1]==s[1]) n1++;
	while(n2<l2&&t[n2+1]==t[1]) n2++;
	if(n2>n1) return 0;
	for(i=2;i<=l1;i++){
		if(j>l2) break;
		j++;
		while(j<=l2){
			if(s[i]==t[j]) break;
			j++;
		}
	}
	if(i>l1&&j<=l2) return 1;
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		if(fuck()) printf("Yes\n");
		else printf("No\n");
 return 0;
}