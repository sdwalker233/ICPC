#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int x,y,z,sum=0,a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	sum=a+b+c;
	if(sum&1){
		printf("Impossible\n");
		return 0;
	}
	sum/=2;
	x=sum-c;
	y=sum-a;
	z=sum-b;
	if(x<0||y<0||z<0){
		printf("Impossible\n");
		return 0;
	}
	printf("%d %d %d\n",x,y,z);
 return 0;
}