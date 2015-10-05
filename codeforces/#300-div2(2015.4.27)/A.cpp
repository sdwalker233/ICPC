#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	char s[110],ss[12]="CODEFORCES";
	int i,p=0;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++){
		if(s[i]==ss[p]) p++;
	}
	if(p==10) printf("YES\n");
	else printf("NO\n");
 return 0;
}

