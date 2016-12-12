#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	freopen("in.txt","w",stdout);
	int i,n=10,q=10,m=10;
	int u=1,v=2,d=3,A=10001,B=10002,C=10003;
	printf("1\n");
	printf("%d %d %d\n",n,q,m);
	for(i=2;i<=n;i++){
		printf("%d ",i-1);
	}
	printf("\n");
	printf("%d %d %d %d %d %d\n",u,v,d,A,B,C);
 return 0;
}

