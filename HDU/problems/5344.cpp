#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,z,l;

void fuck()
{
	int i,ans=0;
	long long a=0;
	scanf("%d%d%d%d",&n,&m,&z,&l);
	for(i=2;i<=n;i++){
		a=((a*m)+z)%l;
		ans^=2*a;
	}
	printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		fuck();
 return 0;
}

