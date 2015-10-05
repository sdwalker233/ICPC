#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 110
using namespace std;
char sub[MAX],fa[MAX],l1,l2;
bool judge()
{
	int i,j=1;
	for(i=1;i<=l1;i++){
		if(j<=l2&&fa[i]==sub[j]) j++;
	}
	if(j>l2) return 1;
	return 0;
}

int main()
{
	
	scanf("%s",fa+1);
	l1=strlen(fa+1);
	for(int i=0;i<1000;i+=8){
		itoa(i,sub+1,10);
		l2=strlen(sub+1);
		if(judge()){
			printf("YES\n");
			printf("%d\n",i);
			return 0;
		}
	}
	printf("NO\n");
 return 0;
}

