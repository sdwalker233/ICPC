#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void fuck()
{
	int i,j,p,q;
	long long ans=0;
	scanf("%d%d",&p,&q);
	if(__builtin_ffs(p)>__builtin_ffs(q)){
		ans+=__builtin_ffs(p)+1;
		p=0;
	}
	for(i=30;i>=0;i--){
		if(((1<<i)&p)==1&&((1<<i)&q)==0){
			j=1;
			while(((1<<i)&p)==1){
				p-=j;
				j<<=1;
				ans++;
			}
		}
		if(((1<<i)&p)==0&&((1<<i)&q)==1){
			int pp=p;
			for(j=0;j<i;j++) p&=(1<<j);
			ans+=pp-p;
			p=pp;
		}
	}
	printf("%lld\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

