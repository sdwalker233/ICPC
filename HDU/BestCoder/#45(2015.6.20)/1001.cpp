#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n;

void fuck()
{
	int now,t=0,cnt=0;
	scanf("%I64d",&n);
	while(n){
		now=n%2;
		if(now) t=1;
		else{
			cnt+=t;
			t=0;
		}
		n>>=1;
	}
	cnt+=t;
	printf("%d\n",cnt);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		fuck();
 return 0;
}

