#include<stdio.h>
#include<string.h>

 void run(){
	int ans[101]={0},i,p,tmp;
	char s[101];
	while(1){
		gets(s);
		if(s[0]=='0') break;
		tmp=0;
		for(i=0;i<strlen(s);i++){
			p=strlen(s)-i-1;
			ans[i]+=tmp+s[p]-'0';
			tmp=ans[i]/10;
			ans[i]%=10;
			}
		if(tmp) ans[i]+=tmp;
		}
	i=100;
	while(!ans[i]) i--;
	for(;i>=0;i--)
		printf("%d",ans[i]);
	printf("\n");
 }

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		run();
 return 0;
}
