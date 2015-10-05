#include<iostream>
#include<cstdio>
using namespace std;
int n;

 bool judge(char s[])
 {
 	int i;
 	for(i=1;i<=n;i++)
		if(s[i]!=s[n-i+1]) break;
	if(i>n) return 1;
	return 0;
 }

int main()
{
	int i,last,last1;
	char s[1010];
	while(~scanf("%d",&n)){
		scanf("%s",s+1);
		last=last1=0;
		for(i=1;i<=n;i++)
			if(s[i]=='?'){
				s[i]='a';
				last1=last;
				last=i;
			}
		if(last==0){
			if(judge(s)){
				printf("QwQ\n");
				continue;
			}
		}
		if(judge(s)){
			s[last]='b';
			if(judge(s)){
				s[last]='a';
				s[last1]='b';
				if(judge(s)){
					printf("QwQ\n");
					continue;
				}
			}
		}
		printf("%s\n",s+1);
	}
 return 0;
}

