#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,s,t;
int fuck()
{
	if(s==t){
		if(n==1) return 0;
		else return -1;
	}
	if(s==1){
		if(t==n) return 0;
		else return 1;
	}
	if(s==n){
		if(t==1) return 0;
		else return 1;
	}
	if(s==t+1||t==s+1) return 1;
	return 2;
}

int main()
{
	while(~scanf("%d%d%d",&n,&s,&t))
		printf("%d\n",fuck());
 return 0;
}