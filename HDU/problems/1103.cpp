#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int i,num,l,a[1010],len;
	char s[1010];
	while(~scanf("%s",s)){
		l=strlen(s);
		s[l]='5';
		num=-1;len=0;
		for(i=0;i<=l;i++){
			if(s[i]=='5'){
				if(num>=0) a[++len]=num;
				num=-1;
			}
			else{
				if(num==-1) num=s[i]-'0';
				else{
					num*=10;
					num+=s[i]-'0';
				}
			}
		}
		sort(a+1,a+len+1);
		for(i=1;i<len;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[len]);
	}
 return 0;
}

