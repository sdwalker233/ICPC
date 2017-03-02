#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[10];
	int i,n,p=0,x;
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d%s",&x,s);
		if(p==0&&s[0]!='S') break;
		if(p==20000&&s[0]!='N') break;
		if(s[0]=='E'||s[0]=='W') continue;
		if(s[0]=='N'){
			p-=x;
			if(p<0) break;
		}
		if(s[0]=='S'){
			p+=x;
			if(p>20000) break;
		}
	}
	if(i>n&&p==0) printf("YES\n");
	else printf("NO\n");
 return 0;
}
