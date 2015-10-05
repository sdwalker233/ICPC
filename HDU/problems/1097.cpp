#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int loop[]={1,1,4,4,2,1,1,4,4,2};
int d[11][10]={{0},{1},{6,2,4,8},{1,3,9,7},{6,4},{5},{6},{1,7,9,3},{6,8,4,2},{1,9}};

int main()
{
	long long a,b;
	while(~scanf("%lld%lld",&a,&b))
		printf("%d\n",d[a%10][b%loop[a%10]]);
 return 0;
}
