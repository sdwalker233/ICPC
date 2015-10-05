#include<stdio.h>
#include<string.h>
char s1[100010]={0},s2[100010]={0};
int main()
{
	int diff=0,i,l;
	scanf("%s%s",s1,s2);
	l=strlen(s1);
	for(i=0;i<l;i++)
		if(s1[i]!=s2[i]) diff++;
	if(diff%2){
		printf("impossible\n");
		return 0;
	}
	diff/=2;
	for(i=0;i<l;i++){
		if(s1[i]!=s2[i]&&diff>0){
			printf("%c",s2[i]);
			diff--;
		}
		else printf("%c",s1[i]);
	}
 return 0;
}

