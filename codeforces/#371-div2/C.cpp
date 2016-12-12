#include <bits/stdc++.h>
using namespace std;
map<long long,int> mp;

long long tran(char s[])
{
	int i,l=strlen(s),num=0;
	for(i=l-1;i>=0;i--){
		if((s[i]-'0')%2) num|=(1<<(l-i-1));
	}
	return num;
}

int main()
{
	int n;
	char op[10],s[100];
	scanf("%d",&n);
	while(n-->0){
		scanf("%s%s",op,s);
		long long num=tran(s);
		if(op[0]=='+') mp[num]++;
		else if(op[0]=='-') mp[num]--;
		else printf("%d\n",mp[num]);
	}
 return 0;
}

