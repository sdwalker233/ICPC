#include<bits/stdc++.h>
using namespace std;

int main()
{
	int d;
	char s1[100],s2[100];
	scanf("%d%s%s",&d,s1,s2);
	if(s2[strlen(s2)-1]=='k'){
		if(d==5||d==6) printf("53\n");
		else printf("52\n");
	}
	else{
		if(d<=29) printf("12\n");
		if(d==30) printf("11\n");
		if(d==31) printf("7\n");
	}
 return 0;
}


