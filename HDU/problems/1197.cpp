#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool check(int x)
{
	int i,sum1=0,sum2=0,sum3=0,n,p;
	n=x;
	while(n){
		sum1+=n%10;
		n/=10;
	}
	n=x;
	while(n){
		sum2+=n%12;
		n/=12;
	}
	n=x;
	while(n){
		sum3+=n%16;
		n/=16;
	}
	if(sum1==sum2&&sum1==sum3) return 1;
	return 0;
}

int main()
{
	int i;
	for(i=2992;i<=9999;i++)
		if(check(i)) printf("%d\n",i);
 return 0;
}