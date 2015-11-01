#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[10][10];
	int i,j,k,x=8,y=8;
	for(i=1;i<=8;i++){
		scanf("%s",&s[i][1]);
	}
	for(i=1;i<=8;i++){
		for(j=1;j<=8;j++){
			if(s[j][i]!='.') break;
		}
		if(j>8||s[j][i]=='B') continue;
		else x=min(x,j-1);
	}
	for(i=1;i<=8;i++){
		for(j=8;j>=1;j--){
			if(s[j][i]!='.') break;
		}
		if(j<1||s[j][i]=='W') continue;
		else y=min(y,8-j);
	}
	//printf("%d %d\n",x,y);
	if(x<=y) printf("A\n");
	else printf("B\n");
 return 0;
}