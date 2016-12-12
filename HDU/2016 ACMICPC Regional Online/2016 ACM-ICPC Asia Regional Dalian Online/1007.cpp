#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long n,m;

bool fuck()
{
	if(n<(m/2)*((m+1)/2)) return 0;
	return 1;
}

int main()
{
	while(~scanf("%lld%lld",&m,&n)){
		if(fuck()) printf("T\n");
		else printf("F\n");
	}
 return 0;
}

