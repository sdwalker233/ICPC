#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,t;
char s[200010];

int main()
{
	int i,l,f=0,jin=0;
	scanf("%d%d",&n,&t);
	scanf("%s",&s[1]);
	l=n;
	for(l=1;l<=n;l++) if(s[l]=='.') break;
	for(;l<n;l++) if(s[l]>='5') break;
	for(i=l;i>=1;i--){
		if(s[i]=='.'){
			f=1;
			continue;
		}
		int num=s[i]-'0'+jin;
		//printf("%d %d %d %d\n",i,jin,num,s[i]);
		jin=0;
		if(num>=10){
			jin=1;
			num-=10;
		}
		if(f==0&&t&&num>=5){
			l=i-1;
			num=0;
			jin++;
			t--;
		}
		s[i]=num+'0';
	}
	while(s[l]=='0'||s[l]=='.'){
		l--;
		if(s[l+1]=='.') break;
	}
	if(jin) printf("%d",jin);
	for(i=1;i<=l;i++)
		printf("%c",s[i]);
 return 0;
}

