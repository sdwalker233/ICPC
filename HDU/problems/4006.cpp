#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,k;

void fuck()
{
	priority_queue<int,vector<int>,greater<int> > qu;
	int i,v;
	char s[10];
	for(i=1;i<=n;i++){
		scanf("%s",s);
		if(s[0]=='I'){
			scanf("%d",&v);
			qu.push(v);
			if(qu.size()>k) qu.pop();
		}
		else{
			printf("%d\n",qu.top());
		}
	}
}

int main()
{
	while(~scanf("%d%d",&n,&k))
		fuck();
 return 0;
}

