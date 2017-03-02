#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
struct node {
	string s;
	int v;
}a[110];
int n;
map<string,int> mp;

bool cmp(const node& x, const node &y)
{
	return x.v>y.v;
}

void fuck()
{
	int i;
	mp.clear();
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		cin>>a[i].s>>a[i].v;
	}
	sort(a+1,a+n+1,cmp);
	int sum=0;
	for(i=1;i<=n;i++){
		if(mp[a[i].s]<2){
			sum+=a[i].v;
			mp[a[i].s]++;
		}
	}
	printf("%d\n",sum);
}

int main()
{
	int i,t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}

