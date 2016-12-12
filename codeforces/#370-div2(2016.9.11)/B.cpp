#include <bits/stdc++.h>
using namespace std;
char s[100010];
int n;

int main()
{
	int i;
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n%2){
		printf("-1\n");
		return 0;
	}
	int u=0,d=0,l=0,r=0;
	for(i=1;i<=n;i++)
		switch(s[i]){
			case('U'):u++;break;
			case('D'):d++;break;
			case('L'):l++;break;
			case('R'):r++;break;
		}
	int x=abs(u-d),y=abs(l-r);
	printf("%d\n",(x+y)/2);
 return 0;
}

