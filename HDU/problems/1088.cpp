#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	char s[100];
	int l=0,i;
	while(~scanf("%s",s)){
		if(strcmp(s,"<br>")==0){
			printf("\n");
			l=0;
		}
		else if(strcmp(s,"<hr>")==0){
			if(l) printf("\n");
			printf("--------------------------------------------------------------------------------\n");
			l=0;
		}
		else if(l==0){
			printf("%s",s);
			l=strlen(s);
		}
		else if(l+strlen(s)+1>80){
			printf("\n%s",s);
			l=strlen(s);
		}
		else{
			printf(" %s",s);
			l+=strlen(s)+1;
		}
	}
	printf("\n");
 return 0;
}

