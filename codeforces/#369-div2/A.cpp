#include <bits/stdc++.h>
using namespace std;
char s[1010][10];

int main()
{
	int n,i,f=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s",s[i]);
		if(f==0)
		if(s[i][0]=='O'&&s[i][1]=='O'){
			f=1;
			s[i][0]=s[i][1]='+';
		}
		if(f==0)
		if(s[i][3]=='O'&&s[i][4]=='O'){
			f=1;
			s[i][3]=s[i][4]='+';
		}
	}
	if(f){
		printf("YES\n");
		for(i=1;i<=n;i++)
			puts(s[i]);
	}
	else printf("NO\n");
 return 0;
}

