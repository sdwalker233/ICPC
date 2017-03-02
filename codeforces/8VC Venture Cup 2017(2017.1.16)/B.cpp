#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main()
{
	string s;
	int n,m,p,i;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>s;
		mp[s]=1;
	}
	for(i=1;i<=m;i++){
		cin>>s;
		p+=mp[s];
	}
	n-=p;
	m-=p;
	if(p%2==0){
		if(n>=m) printf("YES\n");
		else printf("NO\n");
	}
	else{
		if(n<=m) printf("NO\n");
		else printf("YES\n");
	}
 return 0;
}

