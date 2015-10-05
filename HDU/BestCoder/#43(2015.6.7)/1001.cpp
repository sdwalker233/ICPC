#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

 void fuck()
 {
	 int i,l;
	 char s[110];
	 scanf("%s",s+1);
	 l=strlen(s+1);
	 for(i=1;i<=l;i+=2)
		printf("%c",s[i]);
	printf("\n");
	for(i=l;i>=1;i-=2)
		printf("%c",s[i]);
	printf("\n");
 }
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		fuck();
	}
 return 0;
}

