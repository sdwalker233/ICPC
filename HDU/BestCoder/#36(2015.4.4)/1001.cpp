#include<stdio.h>
#include<string.h>
char s[100];

 bool judge(){
 	int l=strlen(s),i,p;
 	char a,b,c;
 	if(l%3) return 0;
 	p=l/3;
 	a=s[0];b=s[p];c=s[p*2];
 	if(a==b||b==c||a==c) return 0;
 	for(i=0;i<l;i++)
 		if(s[i]!=s[i/p*p]) return 0;
 	return 1;
 }

int main()
{
	while(~scanf("%s",s)){
		if(judge()) printf("Yes\n");
		else printf("No\n");
	}
 return 0;
}

