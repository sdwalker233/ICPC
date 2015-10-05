#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;

void fuck()
{
	int i,op,x,mx=-0x80000000,num1=0,num2=0;
	for(i=1;i<=n;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&x);
			mx=max(mx,x);
			num1++;
		}
		if(op==2){
			if(num2<num1) num2++;
			if(num1==num2) mx=-0x80000000;
		}
		if(op==3){
			if(num2==num1) printf("0\n");
			else printf("%d\n",mx);
		}
	}
}

int main()
{
	while(~scanf("%d",&n))
		fuck();
 return 0;
}

