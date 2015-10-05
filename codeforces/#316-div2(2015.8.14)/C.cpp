#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[300010]={0};
int a[300010];
int main()
{
	int i,n,m,sum=0,p;
	char c[10];
	scanf("%d%d%s",&n,&m,s+1);
	for(i=2;i<=n;i++)
		if(s[i]=='.'&&s[i-1]=='.') sum++;
	for(i=1;i<=m;i++){
		scanf("%d%s",&p,c);
		if(c[0]=='.'){
			if(s[p]=='.') printf("%d\n",sum);
			else{
				if(s[p-1]=='.') sum++;
				if(s[p+1]=='.') sum++;
				printf("%d\n",sum);
			}
			s[p]=c[0];
		}
		else{
			if(s[p]!='.') printf("%d\n",sum);
			else{
				if(s[p-1]=='.') sum--;
				if(s[p+1]=='.') sum--;
				printf("%d\n",sum);
			}
			s[p]=c[0];
		}
	}
 return 0;
}


