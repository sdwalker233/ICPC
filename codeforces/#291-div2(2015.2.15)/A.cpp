#include<stdio.h>

int main()
{
	bool ok=0;
	char ch;
	while(scanf("%c",&ch)!=EOF){
		//ch=getchar();
		if(ch=='\n'){
			printf("\n");
			break;
		}
		if(ch>'4') ch='9'-ch+'0';
		if(ok==0&&ch=='0') printf("9");
		else printf("%c",ch);
		ok=1;
	}
 return 0;
}

