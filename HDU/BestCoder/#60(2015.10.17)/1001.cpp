#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
void fuck()
{
	int i;
	long long mx=-0x7fffffffffffffff,mn1=0x7fffffffffffffff,mn2=0x7fffffffffffffff,x,p=1;
	int n0=0;
	scanf("%d",&n);
	if(n==1){
		scanf("%I64d",&p);
		printf("%I64d\n",p);
		return;
	}
	for(i=1;i<=n;i++){
		scanf("%I64d",&x);
		if(x==0){
			n0++;
			continue;
		}
		//mn2=min(mn2,x);
		//if(mn1>mn2) swap(mn1,mn2);
		p*=x;
		if(x<0) mx=max(mx,x);
	}
	if(n0==n){
		printf("0\n");
		return;
	}
	if(n0+1==n&&p<0){
		printf("0\n");
		return;
	}
	if(p<0) printf("%I64d\n",p/mx);
	else printf("%I64d\n",p);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}
