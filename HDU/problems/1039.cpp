#include<stdio.h>
#include<string.h>
bool isvowel(char s)
{
	if(s=='a'||s=='e'||s=='o'||s=='i'||s=='u') return 1;
	return 0;
}

int main()
{
	int i;
	char s[50],s1[]="end";
	bool ok,ok2,a[50];
	while(1){
		gets(s);
		if(!strcmp(s,s1)) break;
		ok=1;ok2=0;
		for(i=0;i<strlen(s);i++){
			a[i]=isvowel(s[i]);
			if(a[i]) ok2=1;
			if(i>=2&&a[i]==a[i-1]&&a[i]==a[i-2]) ok=0;
			if(i>=1&&s[i]==s[i-1]&&s[i]!='e'&&s[i]!='o') ok=0;
		}
		printf("<%s> is ",s);
		if(ok==0||ok2==0) printf("not ");
		printf("acceptable.\n");
	}
 return 0;
}

