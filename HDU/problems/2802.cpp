#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n,m=2009,x,y,z;
	while(~scanf("%d",&n)&&n){
		if(n%2){
			x=((n+1)/2)%m;
			y=(2*n-1)%m;
			printf("%d\n",((x*x)%m*y)%m);
		}
		else{
			x=(n/2)%m;
			y=n%m;
			printf("%d\n",(((x*y)%m*y)%m+(3*(x*x)%m))%m);
		}
	}
 return 0;
}
