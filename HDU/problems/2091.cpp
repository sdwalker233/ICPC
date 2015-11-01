#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
char s[5];

void space(int x)
{
	int i;
	for(i=1;i<=x;i++){
		putchar(' ');
	}
}

void fuck()
{
	int i;
	scanf("%d",&n);
	if(n==1){
		printf("%c\n",s[0]);
		return;
	}
	space(n-1);putchar(s[0]);puts("");
	for(i=2;i<n;i++){
		space(n-i);
		putchar(s[0]);
		space(2*i-3);
		putchar(s[0]);
		puts("");
	}
	for(i=1;i<2*n;i++)
		putchar(s[0]);
	puts("");
}

int main()
{
	bool ok=0;
	while(scanf("%s",s)&&s[0]!='@'){
		if(ok) puts("");
		ok=1;
		fuck();
	}
 return 0;
}