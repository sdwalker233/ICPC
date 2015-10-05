#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
struct node{
	int num;
	string s;
	bool is;
}a[150];

int n,g,s,c,m;

bool cmp(const node& x,const node& y)
{
	if(x.num!=y.num) return x.num>y.num;
	return x.s<y.s;
}

void fuck()
{
	int i;
	for(i=1;i<=n;i++){
		cin>>a[i].num>>a[i].s;
		if(i==m) a[i].is=1;
		else a[i].is=0;
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++){
		if(a[i].is){
			if(i<=g) printf("Accepted today? I've got a golden medal :)\n");
			else if(i>g&&i<=g+s) printf("Accepted today? I've got a silver medal :)\n");
			else if(i>g+s&&i<=g+s+c) printf("Accepted today? I've got a copper medal :)\n");
			else printf("Accepted today? I've got an honor mentioned :)\n");
		}
	}
}

int main()
{
	while(~scanf("%d%d%d%d%d",&n,&g,&s,&c,&m)&&n)
		fuck();
 return 0;
}