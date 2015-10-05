#include<stdio.h>
#include<string.h>
int main()
{
	char s[101],ch;
	while(1){
		scanf("%s",s);
		if(strcmp(s,"ENDOFINPUT")==0) break;
		getchar();
		while(1){
			ch=getchar();
			if(ch=='\n') break;
			if(ch>='A'&&ch<='E') printf("%c",ch+21);
			else if(ch>='F'&&ch<='Z') printf("%c",ch-5);
				else printf("%c",ch);
			}
		printf("\n");
		scanf("%s",s);
	}
 return 0;
}

