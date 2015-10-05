#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int ans=0,i,l;
	char s[20];
	scanf("%s",s);
	l=strlen(s);
	for(i=l-1;i>=0;i--)
		if(s[i]=='7') ans+=(1<<(l-1-i))<<1;
		else ans+=(1<<(l-1-i));
	printf("%d\n",ans);
 return 0;
}

