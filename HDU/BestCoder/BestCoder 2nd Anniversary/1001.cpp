#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[10000010];
int x[10000010],y;

void fuck()
{
	int i,j,l,a[12]={0},len=0;
	scanf("%s",s+1);
	l=strlen(s+1);
	for(i=1;i<=l;i++){
		a[s[i]-'0']++;
	}
	if(a[0]==l-1){
		printf("Uncertain\n");
		return;
	}
	for(i=1;i<=9;i++)
		if(a[i]) break;
	y=i;
	for(i=0;i<=9;i++)
		for(j=1;j<=a[i]-(y==i);j++)
			x[++len]=i;
	for(i=1;i<=len;i++){
		x[i]+=y;
		y=x[i]/10;
		x[i]%=10;
	}
	if(y) x[++len]=y;
	for(i=len;i>=1;i--) printf("%d",x[i]);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0){
		fuck();
	}
 return 0;
}

