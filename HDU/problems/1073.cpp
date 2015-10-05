#include<string.h>
#include<stdio.h>

 void del(char s[])
 {
	 int i,n=0;
	 for(i=0;i<strlen(s);i++)
		 if(s[i]!=' '&&s[i]!='\t'&&s[i]!='\n') s[n++]=s[i];
	 s[n]=0;
 }

 void run()
 {
	 int l1=0,l2=0;
	 char s1[5050]={0},s2[5050]={0},s[10];
	 gets(s);
	 while(1){
		s1[l1++]=getchar();
		if(strcmp(s1+l1-4,"\nEND")==0) break;
	 }
	 getchar();
	 gets(s);
	 while(1){
		s2[l2++]=getchar();
		//printf("%s\n",s2+l2-3);
		if(strcmp(s2+l2-4,"\nEND")==0) break;
	 }
	 getchar();
	 if(strcmp(s1,s2)==0){
		printf("Accepted\n");
		return;
	 }
	 //puts(s1);
	 //puts(s2);
	 del(s1);
	 del(s2);
	 if(strcmp(s1,s2)==0){
		printf("Presentation Error\n");
		return;
	 }
	 printf("Wrong Answer\n");
 }

int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
		run();
 return 0;
}

