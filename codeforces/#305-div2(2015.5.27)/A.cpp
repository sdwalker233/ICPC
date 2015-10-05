#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	char s[1010];
	int n,i,j,len,l;
	scanf("%s%d",s+1,&n);
	len=strlen(s+1);
	if(len%n){
		printf("NO\n");
		return 0;
	}
	l=len/n;
	for(i=1;i<=len;i+=l){
		for(j=0;j<l;j++)
			if(s[i+j]!=s[i+l-j-1]){
				printf("NO\n");
				return 0;
			}
	}
	printf("YES\n");
 return 0;
}

