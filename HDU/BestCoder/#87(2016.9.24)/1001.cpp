#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n,a[510];

inline int gcd(int x,int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}

void fuck()
{
	int i,j;
	int g=0,cnt=0,tmp;
	map<int,int> ans,ans2;
	vector<int> res;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		g=gcd(a[i],g);
	}
	//printf(" %d\n",g);
	ans[0]=1;
	for(i=1;i<=n;i++){
		ans2=ans;
		for(map<int,int>::iterator it=ans.begin();it!=ans.end();++it){
			tmp=gcd(a[i],it->first);
			ans2[tmp]++;
		}
		ans=ans2;
	}
	ans[g]--;
	for(i=1;i<=n;i++)
		ans[a[i]]--;
	for(map<int,int>::iterator it=ans.begin();it!=ans.end();++it){
		if(it->second&&it->first) res.push_back(it->first);
	}
	for(i=0;i<res.size()-1;i++)
		printf("%d ",res[i]);
	printf("%d\n",res[i]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

