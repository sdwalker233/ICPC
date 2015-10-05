#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int gcd(int x,int y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
}

int main()
{
	int a,k;
	while(~scanf("%d",&k)){
		if(gcd(k,65)!=1){
			printf("no\n");
			continue;
		}
		a=1;
		while(1){
			if(a*k-47>=0&&(a*k-47)%65==0) break;
			a++;
		}
		printf("%d\n",a);
	}
 return 0;
}

